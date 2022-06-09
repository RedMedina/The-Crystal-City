Texture2D colorMap : register(t0);
Texture2D specMap : register(t1);
Texture2D NormalMap : register(t2);
Texture2D ReflectionMap : register(t3);

SamplerState colorSampler : register(s0);

//AGUA
cbuffer REFLECTMAT : register(b5)
{
    matrix reflectionMatrix;
};

cbuffer WaterTRANS : register(b6)
{
    float waterTranslation;
};

cbuffer ReflectScale : register(b7)
{
    float reflectRefractScale;
};


SamplerState SampleType
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;
    AddressV = Wrap;
};

cbuffer cbChangerEveryFrame : register(b0)
{
    matrix worldMatrix;
};

cbuffer cbNeverChanges : register(b1)
{
    matrix viewMatrix;
};

cbuffer cbChangeOnResize : register(b2)
{
    matrix projMatrix;
};

cbuffer cbChangesOccasionally : register(b3)
{
    float3 cameraPos;
};

cbuffer cbChangesOccasionally : register(b4)
{
    float specForce;
};

struct VS_Input
{
    float4 pos : POSITION;
    float2 tex0 : TEXCOORD0;
    float3 normal : NORMAL0;
};

struct PS_Input
{
    float4 pos : SV_POSITION;
    float2 tex0 : TEXCOORD0;
    float3 normal : TEXCOORD1;
    float3 campos : TEXCOORD2;
    float specForce : TEXCOORD3;
    float3 tangent : TEXCOORD4;
    float3 binormal : TEXCOORD5;
    float3 view : TEXCOORD6;
    float4 reflectionPosition : TEXCOORD7;
    float4 refractionPosition : TEXCOORD8;
};

PS_Input VS_Main(VS_Input vertex)
{
	
    float4 worldPosition;
    matrix reflectProjectWorld;
    matrix viewProjectWorld;

    PS_Input vsOut = (PS_Input) 0;

    vsOut.pos = mul(vertex.pos, worldMatrix);
    vsOut.pos = mul(vsOut.pos, viewMatrix);
    vsOut.pos = mul(vsOut.pos, projMatrix);

    vsOut.tex0 = vertex.tex0;
    vsOut.normal = normalize(mul(vertex.normal, worldMatrix));
	
    /*float3 tangent;
    float3 c1 = cross(vsOut.normal, float3(0.0, 0.0, 1.0));
    float3 c2 = cross(vsOut.normal, float3(0.0, 1.0, 0.0));
	
    if (length(c1) > length(c2))
    {
        tangent = c1;
    }
    else
    {
        tangent = c2;
    }
    vsOut.tangent = normalize(tangent);
	
    float3 binormal;
    binormal = cross(vsOut.normal, vsOut.tangent);
    vsOut.binormal = normalize(binormal);*/
    
    reflectProjectWorld = mul(reflectionMatrix, projMatrix);
    reflectProjectWorld = mul(worldMatrix, reflectProjectWorld);
    
    vsOut.reflectionPosition = mul(vertex.pos, reflectProjectWorld);
    viewProjectWorld = mul(viewMatrix, projMatrix);
    viewProjectWorld = mul(worldMatrix, viewProjectWorld);
	
    worldPosition = mul(vertex.pos, worldMatrix);

    vsOut.campos = cameraPos.xyz - worldPosition.xyz;

    vsOut.campos = normalize(vsOut.campos);

    vsOut.specForce = specForce;
    
    vsOut.refractionPosition = mul(vertex.pos, viewProjectWorld);

    return vsOut;
}

float4 PS_Main(PS_Input pix) : SV_TARGET
{
    float4 textureColor;
    float3 lightDir;
    float lightIntensity;
    float4 color;
    float3 reflection;
    
    float2 reflectTexCoord;
    float2 refractTexCoord;
    float3 normal;
    float4 reflectionColor;
    float4 refractionColor;
    
    float4 bumpMap;
    float4 specular;
    float4 specularMap;
    float4 finalSpec;

    pix.tex0.y += waterTranslation;
    reflectTexCoord.x = pix.reflectionPosition.x / pix.reflectionPosition.w / 2.0f + 0.5f;
    reflectTexCoord.y = -pix.reflectionPosition.y / pix.reflectionPosition.w / 2.0f + 0.5f;
    refractTexCoord.x = pix.refractionPosition.x / pix.refractionPosition.w / 2.0f + 0.5f;
    refractTexCoord.y = -pix.refractionPosition.y / pix.refractionPosition.w / 2.0f + 0.5f;
    
    textureColor = colorMap.Sample(colorSampler, pix.tex0);
    color = float4(0.2, 0.2, 0.2, 1); // ambient color

    specular = float4(0.0, 0.0, 0.0, 1.0); //specular color
    specularMap = specMap.Sample(colorSampler, pix.tex0);

    lightDir = -(float3(0.5f, -1.0f, 0.0f)); // lightDirection
	
    bumpMap = NormalMap.Sample(colorSampler, pix.tex0);
    bumpMap = (bumpMap * 2.0) - 1.0;
    float3 bumpNormal = (bumpMap.x * pix.tangent) + (bumpMap.y * pix.binormal) + (bumpMap.z * pix.normal);
    bumpNormal = normalize(bumpNormal);
    
    normal = (bumpMap.xyz * 2.0f) - 1.0f;
    reflectTexCoord = reflectTexCoord + (normal.xy * reflectRefractScale);
    refractTexCoord = refractTexCoord + (normal.xy * reflectRefractScale);
    reflectionColor = ReflectionMap.Sample(SampleType, reflectTexCoord);
    refractionColor = ReflectionMap.Sample(SampleType, refractTexCoord);
    //reflectionColor = ReflectionMap.Sample(colorSampler, pix.tex0);
    //refractionColor = ReflectionMap.Sample(colorSampler, pix.tex0);
	
	//lightIntensity = saturate(dot(pix.normal, lightDir));
    lightIntensity = saturate(dot(bumpNormal, lightDir));

    if (lightIntensity > 0)
    {
		// Determine the final diffuse color based on the diffuse color and the amount of light intensity.
        color += (float4(1.0f, 1.f, 1.f, 1.0f) /*diffuse color*/ * lightIntensity);

		// Saturate the ambient and diffuse color.
        color = saturate(color);

		// Calculate the reflection vector based on the light intensity, normal vector, and light direction.
        reflection = normalize(2 * lightIntensity * pix.normal - lightDir);

		// Determine the amount of specular light based on the reflection vector, viewing direction, and specular power.
        specular = pow(saturate(dot(reflection, pix.campos)), pix.specForce);
        finalSpec = specular * specularMap;
    }

    color = color * textureColor;

    color = saturate(color + finalSpec);
    
    color = lerp(reflectionColor, refractionColor, 0.6f) * color;
    
    return color;
}