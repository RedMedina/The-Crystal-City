Texture2D textures : register(t0);
Texture2D texturaDia : register(t1);
Texture2D BlendMap : register(t2);
SamplerState colorSampler : register(s0);

cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projMatrix;
	float4 valores;
};

cbuffer cbChangesOccasionally : register(b2)
{
    float Red;
};

cbuffer cbChangesOccasionally : register(b3)
{
    float Blue;
};

cbuffer Colors : register(b1)
{
    float4 colores;
};

struct VS_Input
{
	float4 pos : POSITION;
	float2 tex0 : TEXCOORD0;
};

struct PS_Input
{
	float4 pos : SV_POSITION;
	float2 tex0 : TEXCOORD0;
    float2 blendTex : TEXCOORD1;
    float fogFactor : FOG;
};

PS_Input VS_Main(VS_Input vertex)
{
    float4 vertPos;
	PS_Input vsOut = (PS_Input)0;
	vsOut.pos = mul(vertex.pos, worldMatrix);
	vsOut.pos = mul(vsOut.pos, viewMatrix);
    vertPos = vsOut.pos;
	vsOut.pos = mul(vsOut.pos, projMatrix);
    //vsOut.blendTex = vertex.blendTex;

	vsOut.tex0 = vertex.tex0;
    
    float fogStart = -10.0f;
    float fogEnd = 380.0f;
    vsOut.fogFactor = saturate((fogEnd - vertPos.z) / (fogEnd - (fogStart)));

	return vsOut;
}

float4 PS_Main(PS_Input pix) : SV_TARGET
{
    float4 fColor = float4(1, 0, 0, 1);
    //float4 finalColor = textures.Sample(colorSampler, pix.tex0) + float4(colores);
    float4 fogColor = float4(0.25f, 0.0f, 0.95f, 1.0f);
    float4 finalColor = textures.Sample(colorSampler, pix.tex0);
    float4 Dia = texturaDia.Sample(colorSampler, pix.tex0);
    finalColor = pix.fogFactor * finalColor + (1.0f - pix.fogFactor) * fogColor;
    //float4 textf = (finalColor * BlendMapp) + ((1.0 - BlendMapp) * TexturaStar);
    //fColor = float4((textf.rgb), 1.0f);

	//return finalColorBlue
    return finalColor;
}