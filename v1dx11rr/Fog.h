#ifndef _fog
#define _fog

#include <d3d11.h>
#include <d3dx11.h>
#include <DxErr.h>
#include <D3Dcompiler.h>
#include <d3dx10math.h>
#include <xnamath.h>

struct FogBufferType {
	XMFLOAT4 fogColor;
	float fogStart;
	float fogEnd;
	float padding1;
	float padding2;
};

static struct FogBufferType fog = { XMFLOAT4(0.0f, 0.5f, 0.5f, 1.0f) , -1000.0f, 1000.0f, 0.0f, 0.0f };



#endif
