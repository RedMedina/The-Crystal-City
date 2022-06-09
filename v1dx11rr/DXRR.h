#ifndef _dxrr
#define _dxrr
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <d3dx10math.h>
#include "TerrenoRR.h"
#include "Camara.h"
#include "SkyDome.h"
#include "Billboard.h"
#include "ModeloRR.h"
#include "XACT3Util.h"
#include "skyplaneclass.h"
#include "skyplaneshaderclass.h"
#include "Task.h"
#include "GUI.h"
#include <string>
#include "Text.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "Water.h"
#include "DiamanteGlow.h"
#include "Metallic.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include "Niebla.h"
#include "GUI_Anim.h"
#include <windows.h>
#include <windowsx.h>

#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)

class DXRR {

private:
	int ancho;
	int alto;
public:
	HINSTANCE hInstance;
	HWND hWnd;

	D3D_DRIVER_TYPE driverType;
	D3D_FEATURE_LEVEL featureLevel;

	ID3D11Device* d3dDevice;
	ID3D11DeviceContext* d3dContext;
	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* backBufferTarget;

	ID3D11Texture2D* depthTexture;
	ID3D11DepthStencilView* depthStencilView;

	ID3D11DepthStencilState* depthStencilState;
	ID3D11DepthStencilState* depthStencilDisabledState;

	ID3D11BlendState* alphaBlendState, * commonBlendState;

	int frameBillboard;

	SkyPlaneClass* m_SkyPlane;
	SkyPlaneShaderClass* m_SkyPlaneShader;

	TerrenoRR* terreno;
	SkyDome* skydome;
	BillboardRR* billboard;
	BillboardRR* Planeta;
	BillboardRR* Nebulosa;
	BillboardRR* Luna;
	Camara* camara;
	float Red = 0.0f;
	float VidaAnim = 0.0f;
	float Green = 0.0f;
	float Blue = 0.0f;
	bool RedB = true;
	bool VidaAnimB = true;
	bool BlueB = true;
	float Sky = 0.0f;
	bool SkyB = true;
	float timerDerrota = 10.0f;

	ModeloRR* model;
	ModeloRR* Pasto;
	ModeloRR* PastoL;
	ModeloRR* Auto;
	ModeloRR* Arbol;
	Metallic* Bola;
	ModeloRR* Roca;
	ModeloRR* Roca2;
	ModeloRR* Barril;
	ModeloRR* Mariposa;
	ModeloRR* Arbusto;
	ModeloRR* Fuente;
	ModeloRR* Templo1;
	ModeloRR* Templo2;
	ModeloRR* Pilar;
	ModeloRR* Pilar2;
	ModeloRR* Estatua;
	ModeloRR* Estatua2;
	DiamanteGlow* Diamante;
	Metallic* Bola_P2;
	ModeloRR* CrystalM;
	ModeloRR* Casa;
	ModeloRR* TemploGrande;
	ModeloRR* Columna;
	ModeloRR* Barandal;
	ModeloRR* CasaHogar;
	ModeloRR* CasaGrande;
	ModeloRR* Banca;
	ModeloRR* Farola;

	Niebla* Nieblaa;
	Niebla* Niebla2;

	WateRR* Agua;
	WateRR* AguaPeque;

	//GUI
	GUI_Anim* Vida;
	GUI_Anim* Vida_2;
	GUI_Anim* Vida_1;
	GUI_Anim* Vida_0;
	GUI* F_Persona;
	GUI* T_Persona;
	GUI* Punto_0;
	GUI* Punto_1;
	GUI* Punto_2;
	GUI* Punto_3;
	GUI* Punto_4;
	GUI* Punto_5;

	GUI* Instrucciones;
	GUI* Instrucciones2;
	GUI* Acertijo1;
	GUI* Acertijo2;
	GUI* Acertijo3;
	GUI* Acertijo4;
	GUI* Acertijo5;
	GUI* Perdiste;
	GUI* Ganaste;
	
	//Texto
	Text* Coordenadas;

	//BGM
	ALLEGRO_SAMPLE* BGM;
	ALLEGRO_SAMPLE* GetEscence;
	ALLEGRO_SAMPLE* Victoria;
	ALLEGRO_SAMPLE* Derrota;
	ALLEGRO_SAMPLE* Cuidado;

	float izqder;
	float arriaba;
	float vel;
	bool breakpoint;
	vector2 uv1[32];
	vector2 uv2[32];
	vector2 uv3[32];
	vector2 uv4[32];

	float rotCam;
	int tipoCam;

	float Invencible;

	XACTINDEX cueIndex;
	CXACT3Util m_XACT3;

	Task* Misiones;
	int Mision4_A = 0;
	bool Mision4_Points[3] = {false, false, false};
	float rotGem;
	int VidaAuto = 3;

	float MovBolaP1;
	bool MovBolaPM1;

	float MovBolaP2;
	bool MovBolaPM2;

	float MovBolaP3;
	bool MovBolaPM3;

	float MaripMov = 0.0f;
	bool MariMov2 = true;
	float RotMarip = 0.0f;

	float floatGem;
	bool subir;

	float i = 0;
	float j = 0;

	bool Musica = false;

	bool derrota = false;
	bool victoraiaaa = false;
	float derrotaTerrain = 0;

	float MovPasto = 0;
	bool MovPastoBool = 0;

	/*Colliders*/
	float Estatura_1[3] = { 3.41, -100, 8.5 };
	float Estatura_2[3] = { 96.49, 127.21, 3 };

	float Banca_1x[3] = { -36.0, 34, 5 };
	float Banca_2x[3] = { 89.19, 87.36, 5 };
	float Banca_3x[3] = { 137.22, 100.6, 5 };
	float Banca_4x[3] = { -102.47, 92.43, 5 };

	float Casa_1x[3] = { 100.0, 50, 15};
	float Casa_2x[3] = { 105.0, -8.0, 15 };
	float Casa_3x[3] = { -111.66, 6.61, 15 };
	float Casa_4x[3] = { -29.78, 89.4, 15};

	float columna_1x[3] = { 16.5f, -86, 2 };
	float columna_2x[3] = { -10.5f, -86, 2};
	float columna_3x[3] = { -10.5f, -65, 2};
	float columna_4x[3] = { 16.5f, -65, 2};

	float farola_1x[3] = { 48.0, 41, 1.5 };
	float farola_2x[3] = { 36.0, 9, 1.5 };
	float farola_3x[3] = { 22.0, -18, 1.5 };
	float farola_4x[3] = { -80.0, 67, 1.5 };
	float farola_5x[3] = { 123, 112, 1.5 };

	float Arbol1[3] = { -20.17, -19.35, 1.9 };
	float Arbol2[3] = { -62.54, 20.53, 1.9 };
	float Arbol3[3] = { -46.7, -15.12, 1.9 };
	float Arbol4[3] = { 75, 31.28, 1.9 };
	float Arbol5[3] = { 68, 118 , 1.9 };
	float Arbol6[3] = { -121, 137, 1.9 };
	float Arbol7[3] = { -120, 107, 1.9 };
	float Arbol8[3] = { 105.15, 18.82, 1.9 };
	
	float Arbol9[3] = { 45, -44 , 1.9 };
	float Arbol10[3] = { 35, -98 , 1.9 };
	float Arbol11[3] = { 67, -54 , 1.9 };
	float Arbol12[3] = { -67, -120 , 1.9 };
	float Arbol13[3] = { -90, -100 , 1.9 };
	float Arbol14[3] = { -120, -80 , 1.9 };
	float Pilar1[3] = { 10, 10, 5 };
	float Pilar2_1[3] = { -7, 10, 5 };
	float Pilar3[3] = { 60, -90, 5 };
	float Pilar4[3] = { 110, -90, 5 };
	float Roca_1[3] = { 120, -50, 5 };
	float Roca_2[3] = { -120, 50, 5 };
	float Fuente_1[3] = { -20.5, 13, 19.5 };
	float Fuente_2[3] = { 28.5f, 13, 16.8 };
	float Templo2_1[3] = { 70, -100, 13.5 };
	float Templo2_2[3] = { 100, -100, 13.5 };
	float Templo1_1[3] = { 0, -20, 15.5 };
	float Agua_1[3] = { -20.5, 13, 27 };
	float Agua_2[3] = { 28.5f, 13, 27 };
	float Arbusto_1[3] = { 44, 56, 3.5 };
	float Arbusto_2[3] = { -34, 51, 3.5 };
	float Arbusto_3[3] = { 35, -44, 3.5 };
	float Arbusto_4[3] = { -40, -120, 3.5 };
	float Arbusto_5[3] = { 67, 52, 3.5 };
	float Arbusto_6[3] = { -70, -120, 3.5 };
	
	float Mision1[3] = { 48.0, 41, 2 };
	float Mision3[3] = { -95.56, 113.98, 16.5 };
	
	float Pilar2_1_1[3] = { -32.25, -11.76, 7 };
	float Pilar2_2[3] = { -52.19, 100.52, 7 };
	float Pilar2_3[3] = { -103.32, -33.03, 7 };
	
	float Diamante_Col[3] = { -102, 60, 7 };
	
	float CrystalM_1[3] = { 4.24f, 35.89f, 3.4};
	float CrystalM_2[3] = { 76.75f, 138.28f, 3.4};
	float CrystalM_3[3] = { 56.63f, -6.83f, 3.4};
	float CrystalM_4[3] = { -65.44, 103.49, 3.4};
	float CrystalM_5[3] = { -5.52, 105.65, 3.4};
	float CrystalM_6[3] = { -23.71, 3.53, 3.4 };
	float CrystalM_7[3] = { -40.57, -2.01, 3.4 };
	float CrystalM_8[3] = { -109.53, -45.61, 3.4 };
	float CrystalM_9[3] = { -82.63, 63.41, 3.4 };
	float CrystalM_10[3] = { -91.07, 88, 3.4 };
	float CrystalM_11[3] = { -45.86, 95.78, 3.4 };
	float CrystalM_12[3] = { -107.01, 66.5, 3.4 };
	
	float BolaP_1[3] = { -28.47f, -66.48f, 4.5f};
	float BolaP_2[3] = { 36.09f, -71.35f, 4.5f};
	float BolaP_3[3] = { -52.69f, -100.81f, 4.5f};
	float BolaP_4[3] = { -100, 14.77f, 4.5f};

	float BolaPX1[3] = { -124.84, 62.38, 4.5f};
	float BolaPX2[3] = { -91.79, 47.16, 4.5f };
	float BolaPX3[3] = { -85.27, 71.5, 4.5f };
	
	float BolaP_Mov1[3];
	float BolaP_Mov2[3];
	float BolaP_Mov3[3];
	
	/*Collisiones de rejas 1*/
	float Reja1x_v1[3] = {18.84, -59.69, 3.5};
	float Reja2x_v1[3] = { 23.24, -59.69, 3.5 };
	float Reja3x_v1[3] = { 28.61, -59.69, 3.5 };
	float Reja4x_v1[3] = { 32.52, -59.69, 3.5 };
	float Reja5x_v1[3] = { 37.89, -59.69, 3.5 };
	float Reja6x_v1[3] = { 43.26, -59.69, 3.5 };
	float Reja7x_v1[3] = { 49.13, -59.69, 3.5 };
	float Reja8x_v1[3] = { 54.99, -59.69, 3.5 };
	float Reja9x_v1[3] = { 62.8, -59.69, 3.5 };
	float Reja10x_v1[3] = { 71.6, -59.69, 3.5 };
	float Reja11x_v1[3] = { 79.44, -59.69, 3.5 };
	float Reja12x_v1[3] = { 85.32, -59.69, 3.5 };
	float Reja13x_v1[3] = { 94.15, -59.69, 3.5 };
	float Reja14x_v1[3] = { 101.5, -59.69, 3.5 };
	float Reja15x_v1[3] = { 109.84, -59.69, 3.5 };
	float Reja16x_v1[3] = { 118.67, -59.69, 3.5 };
	float Reja17x_v1[3] = { 125.54, -59.69, 3.5 };
	float Reja18x_v1[3] = { 131.92, -59.69, 3.5 };
	float Reja19x_v1[3] = { 138.7, -59.69, 3.5 };
	/*Collisiones de rejas 2*/
	float Reja_1x_v2[3] = { -13.5, -59.69, 3.5 };
	float Reja__1x_v2[3] = { -14.3, -59.69, 3.5 };
	float Reja1x_v2[3] = { -18.84, -59.69, 3.5 };
	float Reja2x_v2[3] = { -23.24, -59.69, 3.5 };
	float Reja3x_v2[3] = { -28.61, -59.69, 3.5 };
	float Reja4x_v2[3] = { -32.52, -59.69, 3.5 };
	float Reja5x_v2[3] = { -37.89, -59.69, 3.5 };
	float Reja6x_v2[3] = { -43.26, -59.69, 3.5 };
	float Reja7x_v2[3] = { -49.13, -59.69, 3.5 };
	float Reja8x_v2[3] = { -54.99, -59.69, 3.5 };
	float Reja9x_v2[3] = { -62.8, -59.69, 3.5 };
	float Reja10x_v2[3] = { -71.6, -59.69, 3.5 };
	float Reja11x_v2[3] = { -79.44, -59.69, 3.5 };
	float Reja12x_v2[3] = { -85.32, -59.69, 3.5 };
	float Reja13x_v2[3] = { -94.15, -59.69, 3.5 };
	float Reja14x_v2[3] = { -101.5, -59.69, 3.5 };
	float Reja15x_v2[3] = { -109.84, -59.69, 3.5 };
	float Reja16x_v2[3] = { -118.67, -59.69, 3.5 };
	float Reja17x_v2[3] = { -125.54, -59.69, 3.5 };
	float Reja18x_v2[3] = { -131.92, -59.69, 3.5 };
	float Reja19x_v2[3] = { -138.7, -59.69, 3.5 };

	float temploG1[3] = {13.02, -97.45, 4.7};
	float temploG2[3] = {-6.4, -97.45, 4.7};

	float Casa2_1x[3] = {-109.14, 48.47, 2.3};
	float Casa2_2x[3] = { -104.29, 47.89, 2.3};
	float Casa2_3x[3] = {-99.89, 46.62, 2.3};
	float Casa2_4x[3] = {-105.48, 73.99, 2.3};
	float Casa2_5x[3] = { -101.94, 73.17, 2.3};
	float Casa2_6x[3] = {-97.47, 72.38, 2.3};

    DXRR(HWND hWnd, int Ancho, int Alto)
	{
		/*Inicializar allegro5*/
		al_init();
		al_install_keyboard();
		al_install_mouse();
		al_init_acodec_addon();
		al_install_audio();
		
		al_reserve_samples(2);
		BGM = al_load_sample("Assets/BGM/Haven.mp3");
		GetEscence = al_load_sample("Assets/BGM/GetItem.wav");
		Victoria = al_load_sample("Assets/BGM/Victory.mp3");
		Derrota = al_load_sample("Assets/BGM/Derrota.mp3");
		Cuidado = al_load_sample("Assets/BGM/Cuidado.mp3");
		al_play_sample(BGM, 0.075, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		//al_play_sample(sound, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

		tipoCam = 1;
		rotCam = 0;
		breakpoint = false;
		frameBillboard = 0;
		ancho = Ancho;
		alto = Alto;
		driverType = D3D_DRIVER_TYPE_NULL;
		featureLevel = D3D_FEATURE_LEVEL_11_0;
		d3dDevice = 0;
		d3dContext = 0;
		swapChain = 0;
		backBufferTarget = 0;
		IniciaD3D(hWnd);
		izqder = 0;
		arriaba = 0;
		m_SkyPlane = 0;
		m_SkyPlaneShader = 0;
		billCargaFuego();
		camara = new Camara(D3DXVECTOR3(0,80,130), D3DXVECTOR3(0,80,0), D3DXVECTOR3(0,1,0), Ancho, Alto);
		terreno = new TerrenoRR(300, 300, d3dDevice, d3dContext);
		skydome = new SkyDome(32, 32, 100.0f, &d3dDevice, &d3dContext, L"Assets/Images/right2.png", L"Assets/Images/SkyDome.png", L"Assets/Images/skydomeS.png");
		m_SkyPlane = new SkyPlaneClass;
		m_SkyPlane->Initialize(d3dDevice, L"cloud001.dds", L"cloud002.dds");
		m_SkyPlaneShader = new SkyPlaneShaderClass;
		m_SkyPlaneShader->Initialize(d3dDevice, hWnd);
		rotGem = 0.0f;
		Invencible = 60.0f;

		MovBolaP1 = 0.0f;
		MovBolaPM1 = true;
		MovBolaP2 = 0.0f;
		MovBolaPM2 = true;
		MovBolaP3 = 0.0f;
		MovBolaPM3 = true;
		Red = 0.0f;
		Blue = 0.0f;

		floatGem = 0.0f;
		subir = true;

		Misiones = new Task();
		billboard = new BillboardRR(L"Assets/Billboards/fuego-anim.png",L"Assets/Billboards/fuego-anim-normal.png", d3dDevice, d3dContext, 2);
		Planeta = new BillboardRR(L"Assets/Billboards/Planeta.png", L"Assets/Billboards/PlanetaN.png", d3dDevice, d3dContext, 2);
		Luna = new BillboardRR(L"Assets/Billboards/Luna.png", L"Assets/Billboards/LunaN.png", d3dDevice, d3dContext, 2);
		Nebulosa = new BillboardRR(L"Assets/Billboards/Jupiter.png", L"Assets/Billboards/JupiterN.png", d3dDevice, d3dContext, 2);

		

		model = new ModeloRR(d3dDevice, d3dContext, "Assets/Cofre/Cofre.obj", L"Assets/Cofre/Cofre-color.png", L"Assets/Cofre/Cofre-spec.png", L"Assets/Cofre/Cofre-spec.png", 0, 0);
		//Pasto
		Pasto = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Pasto/Pasto.obj", L"Assets/Models/Pasto/Pasto.jpg", L"Assets/Models/Pasto/Pasto.jpg", L"Assets/Models/Pasto/PastoN.png", 10, 10);
		PastoL = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/PastoL/PastoP.obj", L"Assets/Models/PastoL/PastoL.jpg", L"Assets/Models/PastoL/PastoL.jpg", L"Assets/Models/PastoL/PastoLN.png", 0, 0);

		Agua = new WateRR(d3dDevice, d3dContext, "Assets/Models/Agua/Agua.obj", L"Assets/Models/Agua/AguaTextura.png", L"Assets/Models/Agua/AguaTextura.png", L"Assets/Models/Agua/AguaN3.jpg", L"Assets/Models/Agua/right2.png", 0, 0);
		AguaPeque = new WateRR(d3dDevice, d3dContext, "Assets/Models/Agua/Agua2.obj", L"Assets/Models/Agua/AguaTextura.png", L"Assets/Models/Agua/AguaTextura.png", L"Assets/Models/Agua/AguaN3.jpg", L"Assets/Models/Agua/right2.png", 0, 0);

		Auto = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Auto/Racoon2.obj", L"Assets/Models/Auto/RacoonColor.png", L"Assets/Models/Auto/AutoAO.png", L"Assets/Models/Auto/Racoon_Chasis_Normal.jpg", -10, -10);
		Arbol = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Arbol/Arbol.obj", L"Assets/Models/Arbol/ArbolTextura.jpg", L"Assets/Models/Arbol/ArbolTextura.jpg", L"Assets/Models/Arbol/ArbolN.png", 20, 20);
		Bola = new Metallic(d3dDevice, d3dContext, "Assets/Models/Bola_Pinchos/Bola_Pinchos.obj", L"Assets/Models/Bola_Pinchos/Bola.jpg", L"Assets/Models/Bola_Pinchos/Bola.jpg", L"Assets/Models/Bola_Pinchos/NormalMap.png", L"Assets/Images/right2.png", 40, 40);
		
		Roca = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Roca/Roca.obj", L"Assets/Models/Roca/Rock.png", L"Assets/Models/Roca/Rock.jpg", L"Assets/Models/Roca/RockN.jpg", 60, 60);
		Roca2 = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Roca2/Roca2.obj", L"Assets/Models/Roca2/Roca2.jpg", L"Assets/Models/Roca2/Roca2.jpg", L"Assets/Models/Roca2/Roca2N.jpg", 60, 60);

		Barril = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Barril/Barril.obj", L"Assets/Models/Barril/Barril.png", L"Assets/Models/Barril/Barril.png", L"Assets/Models/Barril/BarrilN.png", 80, 80);
		Mariposa = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Mariposa/Mariposa.obj", L"Assets/Models/Mariposa/Yellow.jpg", L"Assets/Models/Mariposa/Yellow.jpg", L"Assets/Models/Mariposa/YellowNormal.jpg", 100, 100);
		Arbusto = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Arbusto/Arbusto.obj", L"Assets/Models/Arbusto/Arbusto.jpg", L"Assets/Models/Arbusto/Arbusto.jpg", L"Assets/Models/Arbusto/ArbustoNormal.jpg", 120, 120);
		Fuente = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Fuente/FontanRender1.obj", L"Assets/Models/Fuente/FuenteC2.png", L"Assets/Models/Fuente/FuenteC.png", L"Assets/Models/Fuente/FuenteN.png", -10, -10);
		Templo1 = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Templo1/Templo1.obj", L"Assets/Models/Templo1/BaseColorTemplo1.png", L"Assets/Models/Templo1/BaseColorTemplo1.png", L"Assets/Models/Templo1/Templo1N.png", -20,-20);
		Templo2 = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Templo3/Templo3.obj", L"Assets/Models/Templo3/BaseColorTemplo3.png", L"Assets/Models/Templo3/BaseColorTemplo3.png", L"Assets/Models/Templo3/Templo3N.png", 60, 60);
		Pilar = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Pilar/Pilar.obj", L"Assets/Models/Pilar/Pilar.png", L"Assets/Models/Pilar/Pilar.png", L"Assets/Models/Pilar/PilarN.png", -40, -40);
		Pilar2 = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Pilar/Pilar2.obj", L"Assets/Models/Pilar/Pilar.png", L"Assets/Models/Pilar/Pilar.png", L"Assets/Models/Pilar/PilarN.png", -40, -40);
		Estatua = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Estatua/statue.obj", L"Assets/Models/Estatua/statue_texture.png", L"Assets/Models/Estatua/statue_spec.png", L"Assets/Models/Estatua/statue_normal.png", -40, -40);
		Estatua2 = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Estatua2/Estatua2.obj", L"Assets/Models/Estatua2/Estatua2.png", L"Assets/Models/Estatua2/Estatua2.png", L"Assets/Models/Estatua2/Estatua2N.jpg", -40, -40);
		Diamante = new DiamanteGlow(d3dDevice, d3dContext, "Assets/Models/Diamond/diamond.obj", L"Assets/Models/Diamond/DiamondColor.png", L"Assets/Models/Diamond/DiamondColor.png", L"Assets/Models/Diamond/DiamondN.png", L"Assets/Models/Diamond/Glow.png", -40, -40);
		Bola_P2 = new Metallic(d3dDevice, d3dContext, "Assets/Models/Bola_Pinchos2/B_Pinchos.obj", L"Assets/Models/Bola_Pinchos2/B_PinchosC.png", L"Assets/Models/Bola_Pinchos2/B_PinchosC.png", L"Assets/Models/Bola_Pinchos2/B_PinchosN.png", L"Assets/Images/right2.png" , -40, -40);
		CrystalM = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/CristalM/CrystalM.obj", L"Assets/Models/CristalM/CrystalC.png", L"Assets/Models/CristalM/CrystalC.png", L"Assets/Models/CristalM/CrystalN.png", -40, -40);
		Casa = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Casa/Casa.obj", L"Assets/Models/Casa/CasaTextura.png", L"Assets/Models/Casa/CasaTextura.png", L"Assets/Models/Casa/CasaNormal.png", -40, -40);
		TemploGrande = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/TemploGrande/TemploGrande.obj", L"Assets/Models/TemploGrande/TemploG.png", L"Assets/Models/TemploGrande/TemploG.png", L"Assets/Models/TemploGrande/TemploGN.png", -40, -40);
		Columna = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Columna/ConcreteColumn.obj", L"Assets/Models/Columna/ColumnaC.png", L"Assets/Models/Columna/ColumnaC.png", L"Assets/Models/Columna/ColumnaN.png", -40, -40);
		Barandal = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Barandal/railingobj.obj", L"Assets/Models/Barandal/Barandal.png", L"Assets/Models/Barandal/Barandal.png", L"Assets/Models/Barandal/BarandalN.png", -40, -40);
		CasaHogar = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/CasaHogar/CasaHogar.obj", L"Assets/Models/CasaHogar/CasaHogarTx1.png", L"Assets/Models/CasaHogar/CasaHogarTx.png", L"Assets/Models/CasaHogar/CasaHogarN.png", -40, -40);
		CasaGrande = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/CasaGrande/CasaGrande.obj", L"Assets/Models/CasaGrande/CasaGrandeTx1.png", L"Assets/Models/CasaGrande/CasaGrandeTx.png", L"Assets/Models/CasaGrande/CasaGrandeN.png", -40, -40);
		Banca = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Banca/Bank_02.obj", L"Assets/Models/Banca/BancaC.png", L"Assets/Models/Banca/BancaC.png", L"Assets/Models/Banca/BancaN.png", -40, -40);
		Farola = new ModeloRR(d3dDevice, d3dContext, "Assets/Models/Farola/farola.obj", L"Assets/Models/Farola/FarolaC.png", L"Assets/Models/Farola/FarolaC.png", L"Assets/Models/Farola/FarolaN.png", -40, -40);
		
		Nieblaa = new Niebla(d3dDevice, d3dContext, "Assets/Models/Niebla/Niebla.obj", L"Assets/Models/Niebla/NieblaTex.png", L"Assets/Models/Niebla/NieblaTex.png", L"Assets/Models/Niebla/NieblaN.png", -40, -40);
		Niebla2 = new Niebla(d3dDevice, d3dContext, "Assets/Models/Niebla/Niebla2.obj", L"Assets/Models/Niebla/NieblaTex.png", L"Assets/Models/Niebla/NieblaTex.png", L"Assets/Models/Niebla/NieblaN.png", -40, -40);

		Vida = new GUI_Anim(d3dDevice, d3dContext, 0.4f, 0.8f, L"Assets/Images/Life_3.png");
		Vida_2 = new GUI_Anim(d3dDevice, d3dContext, 0.4f, 0.8f, L"Assets/Images/Life_2.png");
		Vida_1 = new GUI_Anim(d3dDevice, d3dContext, 0.4f, 0.8f, L"Assets/Images/Life_1.png");
		Vida_0 = new GUI_Anim(d3dDevice, d3dContext, 0.4f, 0.8f, L"Assets/Images/Life_0.png");

		F_Persona = new GUI(d3dDevice, d3dContext, 1.8f, 1.6f, L"Assets/Images/1erPersona.png");
		T_Persona = new GUI(d3dDevice, d3dContext, 2.7f, 2.4f, L"Assets/Images/3erPersona.png");

		Punto_0 = new GUI(d3dDevice, d3dContext, 0.2f, 0.4f, L"Assets/Images/0_5_Items.png");
		Punto_1 = new GUI(d3dDevice, d3dContext, 0.2f, 0.4f, L"Assets/Images/1_5_Items.png");
		Punto_2 = new GUI(d3dDevice, d3dContext, 0.2f, 0.4f, L"Assets/Images/2_5_Items.png");
		Punto_3 = new GUI(d3dDevice, d3dContext, 0.2f, 0.4f, L"Assets/Images/3_5_Items.png");
		Punto_4 = new GUI(d3dDevice, d3dContext, 0.2f, 0.4f, L"Assets/Images/4_5_Items.png");
		Punto_5 = new GUI(d3dDevice, d3dContext, 0.2f, 0.4f, L"Assets/Images/5_5_Items.png");

		Instrucciones = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/Instrucciones.png");
		Instrucciones2 = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/Instrucciones_2.png");
		Acertijo1 = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/A_1_1.png");
		Acertijo2 = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/A_2.png");
		Acertijo3 = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/A_3.png");
		Acertijo4 = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/A_4.png");
		Acertijo5 = new GUI(d3dDevice, d3dContext, 0.7f, 0.5f, L"Assets/Images/A_5.png");

		Perdiste = new GUI(d3dDevice, d3dContext, 0.8f, 1.0f, L"Assets/Images/Perdiste.png");
		Ganaste = new GUI(d3dDevice, d3dContext, 0.8f, 1.0f, L"Assets/Images/Ganaste.png");


		//Texto
		Coordenadas = new Text(d3dDevice, d3dContext, 3.6, 1.2, L"Assets/Images/font.jpg", XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	}

	~DXRR()
	{
		al_destroy_sample(BGM);
		LiberaD3D();
		m_XACT3.Terminate();
	}
	
	bool IniciaD3D(HWND hWnd)
	{
		this->hInstance = hInstance;
		this->hWnd = hWnd;

		//obtiene el ancho y alto de la ventana donde se dibuja
		RECT dimensions;
		GetClientRect(hWnd, &dimensions);
		unsigned int width = dimensions.right - dimensions.left;
		unsigned int heigth = dimensions.bottom - dimensions.top;

		//Las formas en como la pc puede ejecutar el DX11, la mas rapida es D3D_DRIVER_TYPE_HARDWARE pero solo se puede usar cuando lo soporte el hardware
		//otra opcion es D3D_DRIVER_TYPE_WARP que emula el DX11 en los equipos que no lo soportan
		//la opcion menos recomendada es D3D_DRIVER_TYPE_SOFTWARE, es la mas lenta y solo es util cuando se libera una version de DX que no sea soportada por hardware
		D3D_DRIVER_TYPE driverTypes[]=
		{
			D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_SOFTWARE
		};
		unsigned int totalDriverTypes = ARRAYSIZE(driverTypes);

		//La version de DX que utilizara, en este caso el DX11
		D3D_FEATURE_LEVEL featureLevels[]=
		{
			D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0
		};
		unsigned int totalFeaturesLevels = ARRAYSIZE(featureLevels);

		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = heigth;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hWnd;
		swapChainDesc.Windowed = true;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		HRESULT result;
		unsigned int driver = 0, creationFlags = 0;
		for(driver = 0; driver<totalDriverTypes; driver++)
		{
			result = D3D11CreateDeviceAndSwapChain(0, driverTypes[driver], 0,
				creationFlags, featureLevels, totalFeaturesLevels, 
				D3D11_SDK_VERSION, &swapChainDesc, &swapChain,
				&d3dDevice, &featureLevel, &d3dContext);

			if(SUCCEEDED(result))
			{
				driverType = driverTypes[driver];
				break;
			}
		}

		if(FAILED(result))
		{

			//Error al crear el Direct3D device
			return false;
		}
		
		ID3D11Texture2D* backBufferTexture;
		result = swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);
		if(FAILED(result))
		{
			//"Error al crear el swapChainBuffer
			return false;
		}

		result = d3dDevice->CreateRenderTargetView(backBufferTexture, 0, &backBufferTarget);
		if(backBufferTexture)
			backBufferTexture->Release();

		if(FAILED(result))
		{
			//Error al crear el renderTargetView
			return false;
		}


		D3D11_VIEWPORT viewport;
		viewport.Width = (FLOAT)width;
		viewport.Height = (FLOAT)heigth;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		d3dContext->RSSetViewports(1, &viewport);

		D3D11_TEXTURE2D_DESC depthTexDesc;
		ZeroMemory(&depthTexDesc, sizeof(depthTexDesc));
		depthTexDesc.Width = width;
		depthTexDesc.Height = heigth;
		depthTexDesc.MipLevels = 1;
		depthTexDesc.ArraySize = 1;
		depthTexDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthTexDesc.SampleDesc.Count = 1;
		depthTexDesc.SampleDesc.Quality = 0;
		depthTexDesc.Usage = D3D11_USAGE_DEFAULT;
		depthTexDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthTexDesc.CPUAccessFlags = 0;
		depthTexDesc.MiscFlags = 0;
		
		result = d3dDevice->CreateTexture2D(&depthTexDesc, NULL, &depthTexture);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear la DepthTexture", MB_OK);
			return false;
		}

		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		ZeroMemory(&descDSV, sizeof(descDSV));
		descDSV.Format = depthTexDesc.Format;
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		descDSV.Texture2D.MipSlice = 0;

		result = d3dDevice->CreateDepthStencilView(depthTexture, &descDSV, &depthStencilView);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el depth stencil target view", MB_OK);
			return false;
		}

		d3dContext->OMSetRenderTargets(1, &backBufferTarget, depthStencilView);

		return true;			
		
	}

	void LiberaD3D(void)
	{
		if(depthTexture)
			depthTexture->Release();
		if(depthStencilView)
			depthStencilView->Release();
		if(backBufferTarget)
			backBufferTarget->Release();
		if(swapChain)
			swapChain->Release();
		if(d3dContext)
			d3dContext->Release();
		if(d3dDevice)
			d3dDevice->Release();

		depthTexture = 0;
		depthStencilView = 0;
		d3dDevice = 0;
		d3dContext = 0;
		swapChain = 0;
		backBufferTarget = 0;
	}
	
	void Render(void)
	{
		if(Musica == true)
		{
			al_play_sample(BGM, 0.075, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		}

		float sphere[3] = { 0,0,0 };
		float prevPos[3] = { camara->posCam.x, camara->posCam.z, camara->posCam.z };
		static float angle = 0.0f;
		angle += 0.005;
		if (angle >= 360) angle = 0.0f;
		bool collide = false;
		if( d3dContext == 0 )
			return;

		float clearColor[4] = { 0, 0, 0, 1.0f };
		d3dContext->ClearRenderTargetView( backBufferTarget, clearColor );
		d3dContext->ClearDepthStencilView( depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0 );
		if (tipoCam == 1)
		{
			camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 7;
		}
		else if(tipoCam == 2)
		{
			camara->posCam.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 7;
		}
		
		//camara->posCam3p.y = terreno->Superficie(camara->posCam.x, camara->posCam.z) + 9;
		camara->UpdateCam(vel, arriaba, izqder, tipoCam);

		/*Misiones*/
		if (isPointInsideSphere(camara->getPos(), Estatura_1) && Misiones->GetMision() == 0)
		{
			al_play_sample(GetEscence, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(1);
		}
		else if (isPointInsideSphere(camara->getPos(), Mision1) && Misiones->GetMision() == 1)
		{
			al_play_sample(GetEscence, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(2);
		}
		else if (isPointInsideSphere(camara->getPos(), Estatura_2) && Misiones->GetMision() == 2)
		{
			al_play_sample(GetEscence, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(3);
		}
		else if (isPointInsideSphere(camara->getPos(), Mision3) && Misiones->GetMision() == 3)
		{
			al_play_sample(GetEscence, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(4);
		}
		else if (Mision4_A >= 3 && Misiones->GetMision() == 4)
		{
			al_play_sample(GetEscence, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(5);
		}
		else if (isPointInsideSphere(camara->getPos(), Diamante_Col) && Misiones->GetMision() == 5)
		{
			al_play_sample(GetEscence, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(6);
		}
		else if (isPointInsideSphere(camara->getPos(), Estatura_1) && Misiones->GetMision() == 6)
		{
			al_play_sample(Victoria, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Misiones->SetMision(7);
			victoraiaaa = true;
		}

		if (isPointInsideSphere(camara->getPos(), Pilar2_1_1) && Mision4_Points[0] == false && Misiones->GetMision() == 4)
		{
			Mision4_A++;
			Mision4_Points[0] = true;
		}
		if (isPointInsideSphere(camara->getPos(), Pilar2_2) && Mision4_Points[1] == false && Misiones->GetMision() == 4)
		{
			Mision4_A++;
			Mision4_Points[1] = true;
		}
		if (isPointInsideSphere(camara->getPos(), Pilar2_3) && Mision4_Points[2] == false && Misiones->GetMision() == 4)
		{
			Mision4_A++;
			Mision4_Points[2] = true;
		}

		BolaP_Mov1[0] = 68.42f + MovBolaP1;
		BolaP_Mov1[1] = 108.23f + MovBolaP1;
		BolaP_Mov1[2] = 4;

		BolaP_Mov2[0] = 86.38f;
		BolaP_Mov2[1] = 139.58f + MovBolaP2;
		BolaP_Mov2[2] = 4;

		BolaP_Mov3[0] = 47.32f + MovBolaP3;
		BolaP_Mov3[1] = 102.53f;
		BolaP_Mov3[2] = 4;

		if(isPointInsideSphere(camara->getPos(), CrystalM_1) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_2) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_3) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_4) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_5) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_6) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_7) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_8) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_9) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_10) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_11) ||
		   isPointInsideSphere(camara->getPos(), CrystalM_12) ||
		   isPointInsideSphere(camara->getPos(), BolaPX1) ||
		   isPointInsideSphere(camara->getPos(), BolaPX2) ||
		   isPointInsideSphere(camara->getPos(), BolaPX3)
		   )
		{
			if (Invencible >= 60)
			{
				VidaAuto--;
				Invencible = 0;
			}
			else
			{
				Invencible += 3.5f;
			}
		}

		float CollCam[2] = { camara->posCam.x, camara->posCam.z };
		/*Colisiones*/
		if (camara->posCam.x < -140 || camara->posCam.x > 140 ||
			camara->posCam.z < -140 || camara->posCam.z > 140 ||
			isPointInsideSphere(camara->getPos(), Arbol1) ||
			isPointInsideSphere(camara->getPos(), Arbol2) ||
			isPointInsideSphere(camara->getPos(), Arbol3) ||
			isPointInsideSphere(camara->getPos(), Arbol4) ||
			isPointInsideSphere(camara->getPos(), Arbol5) ||
			isPointInsideSphere(camara->getPos(), Arbol6) ||
			isPointInsideSphere(camara->getPos(), Arbol7) ||
			isPointInsideSphere(camara->getPos(), farola_1x) ||
			isPointInsideSphere(camara->getPos(), farola_2x) ||
			isPointInsideSphere(camara->getPos(), farola_3x) ||
			isPointInsideSphere(camara->getPos(), farola_4x) ||
			isPointInsideSphere(camara->getPos(), farola_5x) ||
			isPointInsideSphere(camara->getPos(), columna_1x) ||
			isPointInsideSphere(camara->getPos(), columna_2x) ||
			isPointInsideSphere(camara->getPos(), columna_3x) ||
			isPointInsideSphere(camara->getPos(), columna_4x) ||
			isPointInsideSphere(camara->getPos(), Casa_1x) ||
			isPointInsideSphere(camara->getPos(), Casa_2x) ||
			isPointInsideSphere(camara->getPos(), Casa_3x) ||
			isPointInsideSphere(camara->getPos(), Casa_4x) ||
			isPointInsideSphere(camara->getPos(), Banca_1x) ||
			isPointInsideSphere(camara->getPos(), Banca_2x) ||
			isPointInsideSphere(camara->getPos(), Banca_3x) ||
			isPointInsideSphere(camara->getPos(), Banca_4x) ||
			isPointInsideSphere(camara->getPos(), Estatura_1) || 
			isPointInsideSphere(camara->getPos(), Reja1x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja2x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja3x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja4x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja5x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja6x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja7x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja8x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja9x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja10x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja11x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja12x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja13x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja14x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja15x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja16x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja17x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja18x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja19x_v1) ||
			isPointInsideSphere(camara->getPos(), Reja_1x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja__1x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja1x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja2x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja3x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja4x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja5x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja6x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja7x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja8x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja9x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja10x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja11x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja12x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja13x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja14x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja15x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja16x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja17x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja18x_v2) ||
			isPointInsideSphere(camara->getPos(), Reja19x_v2) ||
			isPointInsideSphere(camara->getPos(), Arbol8) ||
			isPointInsideSphere(camara->getPos(), Estatura_2) || 
			isPointInsideSphere(camara->getPos(), CrystalM_1) ||
			isPointInsideSphere(camara->getPos(), CrystalM_2) ||
			isPointInsideSphere(camara->getPos(), CrystalM_3) ||
			isPointInsideSphere(camara->getPos(), CrystalM_4) ||
			isPointInsideSphere(camara->getPos(), CrystalM_5) ||
			isPointInsideSphere(camara->getPos(), CrystalM_6) ||
			isPointInsideSphere(camara->getPos(), CrystalM_7) ||
			isPointInsideSphere(camara->getPos(), CrystalM_8) ||
			isPointInsideSphere(camara->getPos(), CrystalM_9) ||
			isPointInsideSphere(camara->getPos(), CrystalM_10) ||
			isPointInsideSphere(camara->getPos(), CrystalM_11) ||
			isPointInsideSphere(camara->getPos(), CrystalM_12) ||
			isPointInsideSphere(camara->getPos(), BolaPX1) ||
			isPointInsideSphere(camara->getPos(), BolaPX2) ||
			isPointInsideSphere(camara->getPos(), BolaPX3) ||
			isPointInsideSphere(camara->getPos(), temploG1) ||
			isPointInsideSphere(camara->getPos(), temploG2) ||
			isPointInsideSphere(camara->getPos(), Casa2_1x) ||
			isPointInsideSphere(camara->getPos(), Casa2_2x) ||
			isPointInsideSphere(camara->getPos(), Casa2_3x) ||
			isPointInsideSphere(camara->getPos(), Casa2_4x) ||
			isPointInsideSphere(camara->getPos(), Casa2_5x) ||
			isPointInsideSphere(camara->getPos(), Casa2_6x)
		   )
		{
			camara->posCam = camara->posCamPast;
		}

		skydome->Update(camara->vista, camara->proyeccion);

		float camPosXZ[2] = { camara->posCam.x, camara->posCam.z };

		TurnOnAlphaBlending();
		TurnOffDepth();
		skydome->Render(camara->posCam, Sky, Red);
		TurnOnDepth();
		terreno->Draw(camara->vista, camara->proyeccion, derrotaTerrain);
		if (derrota == true)
		{
			derrotaTerrain = -VidaAnim;
			timerDerrota -= 0.05f;
			if (timerDerrota < 0)
			{
				KillTimer(hWnd, 100);
				PostQuitMessage(0);
			}
		}
		else if (victoraiaaa == true)
		{
			derrotaTerrain = VidaAnim;
		}
		//TurnOnAlphaBlending();
		//billboard->Draw(camara->vista, camara->proyeccion, camara->posCam,
			//-11, -78, 4, 5, uv1, uv2, uv3, uv4, frameBillboard, true, false);
		Planeta->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-11, -238, -67, 110, uv1, uv2, uv3, uv4, frameBillboard, false, false);
		Luna->Draw(camara->vista, camara->proyeccion, camara->posCam,
			231, -118, 142, 16, uv1, uv2, uv3, uv4, frameBillboard, false, true);
		Nebulosa->Draw(camara->vista, camara->proyeccion, camara->posCam,
			-411, -238, 92, 80, uv1, uv2, uv3, uv4, frameBillboard, false, true);

		//TurnOffAlphaBlending();		
		
		Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(90, 90) - 0.5f + MovPasto, camara->posCam, 10.0f, 0, 'A', 3, false, 0, -30, -4, 1);
		Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-80, 50) - 0.5f + MovPasto, camara->posCam, 10.0f, 0, 'A', 3, false, 0, -115.65, -39.82, 1);
		Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(60, -40) - 0.5f + MovPasto, camara->posCam, 10.0f, 0, 'A', 3, false, 0, 108.9, -37.91, 1);
		Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, -30) - 0.5f + MovPasto, camara->posCam, 10.0f, 0, 'A', 3, false, 0, 134.86, 31.87, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 30, 'Y', 3, false, 0, -126.33, 62.4, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, -70, 80, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, 50, -30, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, 80, 40, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, 90, 70, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, -90, -50, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, -80, -70, 1);
		//Pasto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(70, 30) - 0.5f, camara->posCam, 10.0f, 0, 'A', 3, false, 0, -70, -80, 1);

		//PastoL->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 0, 0, 0);
		
		camara->RenderReflection(2.75f);
		Nieblaa->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0) - 5, camara->posCam, 10.0f, 0, 'A', 1, false, 0, 0, 168.5f, 0, Red);
		Nieblaa->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0) - 5, camara->posCam, 10.0f, 0, 'A', 1, false, 0, 0, -168.5f, 0, Red);
		
		Niebla2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0) - 5, camara->posCam, 10.0f, 0, 'A', 1, false, 0, 168.5f, 0, 0, Red);
		Niebla2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0) - 5, camara->posCam, 10.0f, 0, 'A', 1, false, 0, -168.5f, 0, 0, Red);

		Agua->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0)-1, camara->posCam, 10.0f, 0, 'A', 1, false, 0, 76.5f + floatGem, -100, 0, camara->GetReflectionViewMatrix());
		Agua->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0)-1, camara->posCam, 10.0f, 0, 'A', 1, false, 0, -76.5f + floatGem, -100, 0, camara->GetReflectionViewMatrix());
		
		AguaPeque->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0) - 1, camara->posCam, 10.0f, 0, 'A', 2, false, 0, 115.9f + floatGem, 92.4, 0, camara->GetReflectionViewMatrix());
		AguaPeque->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0) - 1, camara->posCam, 10.0f, 0, 'A', 2, false, 0, -98.8f + floatGem, 115.7, 0, camara->GetReflectionViewMatrix());
		
		TemploGrande->Draw(camara->vista, camara->proyeccion, terreno->Superficie(0, 0), camara->posCam, 10.0f, 0, 'A', 1.3f, false, 0, 3, -118, 0);
		Estatua->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1.3f, false, 0, 3, -118, 0);
		Columna->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 16.5f, -86, 0);
		Columna->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -10.5f, -86, 0);
		Columna->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -10.5f, -65, 0);
		Columna->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 16.5f, -65, 0);
		Barandal->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 78.5f, -65, 0);
		Barandal->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -83.5f, -65, 0);
		CasaHogar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 2, false, 0, 100.0, 50.0, 0);
		CasaHogar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 2, false, 0, 105.0, -8.0, 0);
		CasaHogar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'Y', 2, false, 0, -111.66, 6.61, 0);
		CasaHogar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 90, 'Y', 2, false, 0, -29.78, 89.4, 0);
		CasaGrande->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'Y', 2, false, 0, -102.0, 60, 0);
		
		Banca->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'Y', 1.4, false, 0, -36.0, 34, 0);
		Banca->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, -5, 'Y', 1.4, false, 0, 89.19, 87.36, 0);
		Banca->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, -8, 'Y', 1.4, false, 0, 137.22, 100.6, 0);
		Banca->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'Y', 1.4, false, 0, -102.47, 92.43, 0);

		Farola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'A', 2, false, 0, 48.0, 41, 0);
		Farola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'A', 2, false, 0, 36.0, 9, 0);
		Farola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'A', 2, false, 0, 22.0, -18, 0);
		Farola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'A', 2, false, 0, -80.0, 67, 0);
		//Farola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'A', 2, false, 0, -1.8, -23.23, 0);
		Farola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 30, 'A', 2, false, 0, 123, 112, 0);
		
		Estatua2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, -45, 'Y', 2.5f, false, 0, 96.49, 127.21, 0);

		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -20.17, -19.35, 0);
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -62.54, 20.53, 0);
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -46.7, -15.12, 0);
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 75, 31.28, 0);
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-54, 51), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 68, 118, 0);
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-45, 35), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -121, 137, 0);	
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, 72), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -120, 107, 0);
		Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-77, 44), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 105.15, 18.82, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(45, -44), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 45, -44, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(35, -98), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 35, -98, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54),camara->posCam, 10.0f, 0, 'A', 1, false, 0, 67, -54, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -67, -120, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -90, -100, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -120, -80, 0);

		Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 127, 77, 0);
		Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -68.1, 128.7, 0);
		Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -27, 23, 0);
		Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 66.12, 14.8, 0);
		//Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -29.7, -35, 0);
		
		//Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 80.0, 74.0, 0);
		//Arbusto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(120, 120), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 70.7, 44.22, 0);

		Mariposa->Draw(camara->vista, camara->proyeccion, terreno->Superficie(100, 100) + 35, camara->posCam, 10.0f, RotMarip, 'Y', 1, false, 0, -15.41f + MaripMov, -77.77f, 0);
		Mariposa->Draw(camara->vista, camara->proyeccion, terreno->Superficie(100, 100) + 35, camara->posCam, 10.0f, RotMarip, 'Y', 1, false, 0, 5.38f + MaripMov, -109.04f, 0);

		Pilar2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10) + 2, camara->posCam, 10.0f, 0, 'A', 1, false, 0, -32.25, -11.76, 0);
		Pilar2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10) + 2, camara->posCam, 10.0f, 90, 'Y', 1, false, 0, -52.19, 100.52, 0);
		Pilar2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10) + 2, camara->posCam, 10.0f, 45, 'Y', 1, false, 0, -103.32, -48.03, 0);

		Diamante->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10) + 2, camara->posCam, 10.0f, D3DX_PI / 2 + -rotGem, 'Y', 1, false, 0, -102, 60, 0, Red, Blue);
		
		//Roca->Draw(camara->vista, camara->proyeccion, terreno->Superficie(60, 60), camara->posCam, 10.0f, 90, 'A', 1, false, 0, 120, -50, 0);
		//Roca->Draw(camara->vista, camara->proyeccion, terreno->Superficie(60, 60), camara->posCam, 10.0f, 90, 'A', 1, false, 0, -120, 50, 0);
		
		
		//Bola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -28.47f, -66.48f, 0);
		//Bola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 36.09f, -71.35f, 0);
		//Bola->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -52.69f, -100.81f, 0);
		
		//Bola_P2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 68.42f + MovBolaP1, 108.23f + MovBolaP1, 0);
		//Bola_P2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 86.38f, 139.58f + MovBolaP2, 0);
		//Bola_P2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 47.32f + MovBolaP3, 102.53f, 0);
		
		Bola_P2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -124.84, 62.38, 0);
		Bola_P2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -91.79, 47.16, 0);
		Bola_P2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -85.27, 71.5, 0);

		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 4.24f, 35.89f, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 76.75f, 138.28f, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 56.63f, -6.83f, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -65.44, 103.49, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -5.52, 105.65, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -23.71, 3.53, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -40.57, -2.01, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -109.53, -45.61, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -82.63, 63.41, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -91.07, 88, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -45.86, 95.78, 0);
		CrystalM->Draw(camara->vista, camara->proyeccion, terreno->Superficie(40, 40), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 107.01, 66.5, 0);

		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(34, 56), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 34, 56, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(89, -46), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 89, -46, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-34, -89), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -34, -89, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(62, 34), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 62, 34, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-54, 51), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -54, 51, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-45, 35), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -45, 35, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, 72), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 67, 72, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-77, 44), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -77, 44, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(45, -44), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 45, -44, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(35, -98), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 35, -98, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54),camara->posCam, 10.0f, 0, 'A', 1, false, 0, 67, -54, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -67, -120, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -90, -100, 0);
		//Arbol->Draw(camara->vista, camara->proyeccion, terreno->Superficie(67, -54), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -120, -80, 0);

		//Fuente->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-10, -10), camara->posCam, 10.0f, 0, 'A', 2, false, 0, -20, 13, 0);
		//Fuente->Draw(camara->vista, camara->proyeccion, terreno->Superficie(-10, -10), camara->posCam, 10.0f, 0, 'A', 2, false, 0, 32.5f, 13, 0);
		
		//Pilar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 10, 10, 0);
		//Pilar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -7, 10, 0);
		
		//Templo1->Draw(camara->vista, camara->proyeccion, terreno->Superficie(1, 10), camara->posCam, 10.0f, 45, 'A', 2, false, 0, 1, 10, 0);
		
		//Pilar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 60, -90, 0);
		//Pilar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, 110, -90, 0);

		//Pilar->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10), camara->posCam, 10.0f, 0, 'A', 1, false, 0, -64.5, 11, 0);

		//
		//

		//Templo2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(1, 10), camara->posCam, 10.0f, 45, 'A', 2, false, 0, 70, -100, 0);
		//Templo2->Draw(camara->vista, camara->proyeccion, terreno->Superficie(1, 10), camara->posCam, 10.0f, 45, 'A', 2, false, 0, 100, -100, 0);
		
		//Casa->Draw(camara->vista, camara->proyeccion, terreno->Superficie(10, 10) + 2, camara->posCam, 10.0f, 0, 'A', 1, false, 0, -40, -40, 0);

		rotCam += izqder;
		Auto->setPosX(camara->posCam.x);
		if(tipoCam == 1)
		{
			//Auto->setPosZ(camara->posCam.z);
			//F_Persona->Draw(-0.085f, -0.2);
		}
		else if(tipoCam == 2)
		{
			T_Persona->Draw(-0.085f, 0.2);
			//Auto->setPosZ(camara->posCam.z);
		}
		
		//TurnOffDepth();
		//Auto->Draw(camara->vista, camara->proyeccion, terreno->Superficie(Auto->getPosX(), Auto->getPosZ()) - 1.0f, camara->posCam, 10.0f, rotCam, 'Y', 1, true, tipoCam, 0, 0, 0);
		//TurnOnDepth();

		stringstream ss;
		ss << camara->posCam.x;
		//Coordenadas->DrawText(-0.95, 0.08, "X: " + ss.str(), 0.015);
		ss.str(std::string());
		ss << camara->posCam.z;
		//Coordenadas->DrawText(-0.95, 0.02, "Z: " + ss.str(), 0.015);

		switch (Misiones->GetMision())
		{
		case 0:
			//Punto_0->Draw(-0.8, 0.55);
			//Instrucciones->Draw(-0.75, 0.1);
			break;
		case 1:
			Punto_0->Draw(-0.8, 0.55);
			Acertijo1->Draw(-0.75, 0.1);
			break;
		case 2:
			Punto_1->Draw(-0.8, 0.55);
			Acertijo2->Draw(-0.75, 0.1);
			break;
		case 3:
			Punto_2->Draw(-0.8, 0.55);
			Acertijo3->Draw(-0.75, 0.1);
			break;
		case 4:
			Punto_3->Draw(-0.8, 0.55);
			Acertijo4->Draw(-0.75, 0.1);
			break;
		case 5:
			Punto_4->Draw(-0.8, 0.55);
			Acertijo5->Draw(-0.75, 0.1);
			break;
		case 6:
			Punto_5->Draw(-0.8, 0.55);
			Instrucciones2->Draw(-0.75, 0.1);
			break;
		case 7:
			//Punto_5->Draw(-0.8, 0.55);
			Ganaste->Draw(0, 0);
			break;
		case 8:
			Perdiste->Draw(0, 0);
			break;
		default:
			break;
		}

		switch (VidaAuto)
		{
		case 3:
			Vida->Draw(-0.6, 0.85, 0);
			break;
		case 2:
			Vida_2->Draw(-0.6, 0.85, 0);
			break;
		case 1:
			al_play_sample(Cuidado, 1.0, 0.4, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Vida_1->Draw(-0.6, 0.85, VidaAnim);
			break;
		case 0:
			al_play_sample(Derrota, 1.0, 0.7, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			Vida_0->Draw(-0.6, 0.85, VidaAnim);
			Misiones->SetMision(8);
			derrota = true;
			break;
		default:
			Vida_0->Draw(-0.6, 0.85, VidaAnim);
			//Misiones->SetMision(8);
			break;
		}

		rotGem += 0.01;


		if (SkyB) {
			Sky -= 0.01;
		}
		else {
			Sky += 0.01;
		}

		if (Sky > 0.0) {
			Sky = 0.0f;
			SkyB = false;
		}
		else if (Sky < 1) {
			Sky = 1;
			SkyB = true;
		}

		//-------------------
		if (RedB) {
			Red += 0.01;
		}
		else {
			Red -= 0.01;
		}

		if (Red > 1.0) {
			Red = 1.0f;
			RedB = false;
		}
		else if (Red < 0) {
			Red = 0;
			RedB = true;
		}

		//-------------------
		if (VidaAnimB) {
			VidaAnim += 0.01;
		}
		else {
			VidaAnim -= 0.01;
		}

		if (VidaAnim > 1.0) {
			VidaAnim = 1.0f;
			VidaAnimB = false;
		}
		else if (VidaAnim < 0) {
			VidaAnim = 0;
			VidaAnimB = true;
		}

		//-------------------
		if (BlueB) {
			Blue -= 0.01;
		}
		else {
			Blue += 0.01;
		}

		if (Blue > -1.0) {
			Blue = -1.0;
			BlueB = false;
		}
		else if (Blue < 1.0) {
			Blue = 1.0;
			BlueB = true;
		}

		//-------------------
		if (MovBolaPM1) {
			MovBolaP1 += 0.07;
		}
		else {
			MovBolaP1 -= 0.07;
		}

		if (MovBolaP1 > 3.5) {
			MovBolaP1 = 3.5;
			MovBolaPM1 = false;
		}
		else if (MovBolaP1 < -3.5) {
			MovBolaP1 = -3.5;
			MovBolaPM1 = true;
		}
		//-------------------

		//-------------------
		if (MovBolaPM2) {
			MovBolaP2 += 0.07;
		}
		else {
			MovBolaP2 -= 0.07;
		}

		if (MovBolaP2 > 3.5) {
			MovBolaP2 = 3.5;
			MovBolaPM2 = false;
		}
		else if (MovBolaP2 < -3.5) {
			MovBolaP2 = -3.5;
			MovBolaPM2 = true;
		}
		//-------------------

		//-------------------
		if (MovBolaPM3) {
			MovBolaP3 += 0.07;
		}
		else {
			MovBolaP3 -= 0.07;
		}

		if (MovBolaP3 > 3.5) {
			MovBolaP3 = 3.5;
			MovBolaPM3 = false;
		}
		else if (MovBolaP3 < -3.5) {
			MovBolaP3 = -3.5;
			MovBolaPM3 = true;
		}
		//-------------------

		if (MariMov2) {
			MaripMov += 0.1f;
			RotMarip = 0;
		}
		else {
			MaripMov -= 0.1f;
			RotMarip = 60;
		}

		if (MaripMov > 40) {
			MaripMov = 40;
			MariMov2 = false;
		}
		else if (MaripMov < -40) {
			MaripMov = -40;
			MariMov2 = true;
		}
		//-------------------

		if (subir) {
			floatGem += 0.034;
		}
		else {
			floatGem -= 0.034;
		}

		if (floatGem > 1.5) {
			floatGem = 1.5;
			subir = false;
		}
		else if (floatGem < -1.5) {
			floatGem = -1.5;
			subir = true;
		}

		i < 40 ? i += 0.1f : i = 0;
		j < 5 ? j += 0.5f : j = -5;

		//--------------------
		if (MovPastoBool) {
			MovPasto += 0.002;
		}
		else {
			MovPasto -= 0.002;
		}

		if (MovPasto > 0.1) {
			MovPasto = 0.1;
			MovPastoBool = false;
		}
		else if (MovPasto < -0.1) {
			MovPasto = -0.1;
			MovPastoBool = true;
		}

		TurnOffAlphaBlending();
		
		swapChain->Present( 1, 0 );
	}

	bool isPointInsideSphere(float* point, float* sphere) {
		bool collition = false;

		float distance = sqrt((point[0] - sphere[0]) * (point[0] - sphere[0]) +
			(point[1] - sphere[1]) * (point[1] - sphere[1]));

		if (distance < sphere[2])
			collition = true;
		return collition;
	}

	//Activa el alpha blend para dibujar con transparencias
	void TurnOnAlphaBlending()
	{
		float blendFactor[4];
		blendFactor[0] = 0.0f;
		blendFactor[1] = 0.0f;
		blendFactor[2] = 0.0f;
		blendFactor[3] = 0.0f;
		HRESULT result;

		D3D11_BLEND_DESC descABSD;
		ZeroMemory(&descABSD, sizeof(D3D11_BLEND_DESC));
		descABSD.RenderTarget[0].BlendEnable = TRUE;
		descABSD.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		descABSD.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		descABSD.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		descABSD.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		descABSD.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		descABSD.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		descABSD.RenderTarget[0].RenderTargetWriteMask = 0x0f;

		result = d3dDevice->CreateBlendState(&descABSD, &alphaBlendState);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el blend state", MB_OK);
			return;
		}

		d3dContext->OMSetBlendState(alphaBlendState, blendFactor, 0xffffffff);
	}

	//Regresa al blend normal(solido)
	void TurnOffAlphaBlending()
	{
		D3D11_BLEND_DESC descCBSD;
		ZeroMemory(&descCBSD, sizeof(D3D11_BLEND_DESC));
		descCBSD.RenderTarget[0].BlendEnable = FALSE;
		descCBSD.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		descCBSD.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		descCBSD.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		descCBSD.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		descCBSD.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		descCBSD.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		descCBSD.RenderTarget[0].RenderTargetWriteMask = 0x0f;
		HRESULT result;

		result = d3dDevice->CreateBlendState(&descCBSD, &commonBlendState);
		if(FAILED(result))
		{
			MessageBox(0, L"Error", L"Error al crear el blend state", MB_OK);
			return;
		}

		d3dContext->OMSetBlendState(commonBlendState, NULL, 0xffffffff);
	}

	void TurnOnDepth()
	{
		D3D11_DEPTH_STENCIL_DESC descDSD;
		ZeroMemory(&descDSD, sizeof(descDSD));
		descDSD.DepthEnable = true;
		descDSD.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		descDSD.DepthFunc = D3D11_COMPARISON_LESS;
		descDSD.StencilEnable=true;
		descDSD.StencilReadMask = 0xFF;
		descDSD.StencilWriteMask = 0xFF;
		descDSD.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDSD.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		descDSD.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDSD.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		descDSD.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDSD.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		descDSD.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDSD.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		d3dDevice->CreateDepthStencilState(&descDSD, &depthStencilState);
		
		d3dContext->OMSetDepthStencilState(depthStencilState, 1);
	}

	void TurnOffDepth()
	{
		D3D11_DEPTH_STENCIL_DESC descDDSD;
		ZeroMemory(&descDDSD, sizeof(descDDSD));
		descDDSD.DepthEnable = false;
		descDDSD.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		descDDSD.DepthFunc = D3D11_COMPARISON_LESS;
		descDDSD.StencilEnable=true;
		descDDSD.StencilReadMask = 0xFF;
		descDDSD.StencilWriteMask = 0xFF;
		descDDSD.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		descDDSD.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		descDDSD.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		descDDSD.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		descDDSD.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		d3dDevice->CreateDepthStencilState(&descDDSD, &depthStencilDisabledState);
		d3dContext->OMSetDepthStencilState(depthStencilDisabledState, 1);
	}

	void billCargaFuego()
	{
		uv1[0].u = .125;
		uv2[0].u = .125;
		uv3[0].u = 0;
		uv4[0].u = 0;

		uv1[0].v = .25;
		uv2[0].v = 0;
		uv3[0].v = 0;
		uv4[0].v = .25;


		for (int j = 0; j < 8; j++) {
			uv1[j].u = uv1[0].u + (j * .125);
			uv2[j].u = uv2[0].u + (j * .125);
			uv3[j].u = uv3[0].u + (j * .125);
			uv4[j].u = uv4[0].u + (j * .125);

			uv1[j].v = .25;
			uv2[j].v = 0;
			uv3[j].v = 0;
			uv4[j].v = .25;
		}
		for (int j = 0; j < 8; j++) {
			uv1[j + 8].u = uv1[0].u + (j * .125);
			uv2[j + 8].u = uv2[0].u + (j * .125);
			uv3[j + 8].u = uv3[0].u + (j * .125);
			uv4[j + 8].u = uv4[0].u + (j * .125);

			uv1[j + 8].v = .5;
			uv2[j + 8].v = .25;
			uv3[j + 8].v = .25;
			uv4[j + 8].v = .5;
		}

		for (int j = 0; j < 8; j++) {
			uv1[j + 16].u = uv1[0].u + (j * .125);
			uv2[j + 16].u = uv2[0].u + (j * .125);
			uv3[j + 16].u = uv3[0].u + (j * .125);
			uv4[j + 16].u = uv4[0].u + (j * .125);

			uv1[j + 16].v = .75;
			uv2[j + 16].v = .5;
			uv3[j + 16].v = .5;
			uv4[j + 16].v = .75;
		}

		for (int j = 0; j < 8; j++) {
			uv1[j + 24].u = uv1[0].u + (j * .125);
			uv2[j + 24].u = uv2[0].u + (j * .125);
			uv3[j + 24].u = uv3[0].u + (j * .125);
			uv4[j + 24].u = uv4[0].u + (j * .125);

			uv1[j + 24].v = 1;
			uv2[j + 24].v = .75;
			uv3[j + 24].v = .75;
			uv4[j + 24].v = 1;
		}
	}

};
#endif