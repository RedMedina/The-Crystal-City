#ifndef _camara
#define _camara

//Clase camara hecha por Rafael Rosas para los UltraLMADs
//Videojuegos

#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10math.h>

class Camara{
public:
	D3DXVECTOR3 posCam;
	D3DXVECTOR3 posCam3p;
	D3DXVECTOR3 hdveo;
	D3DXVECTOR3 hdvoy;
	D3DXVECTOR3 refUp;
	D3DXVECTOR3 refRight;
	D3DXVECTOR3 refFront;
	D3DXMATRIX vista;
	D3DXMATRIX proyeccion;
	D3DXMATRIX m_reflectionViewMatrix;
	int ancho;
	int alto;
	float pos[2];
	D3DXVECTOR3 posCamPast;

	Camara(D3DXVECTOR3 eye, D3DXVECTOR3 target, D3DXVECTOR3 up, int Ancho, int Alto)
	{
		//posicion de la camara
		posCam = eye;
		//posCam3p = eye;
		//posCam3p.z += 5;
		//a donde ve
		hdveo = target;
		refUp = up;
		ancho = Ancho;
		alto = Alto;

		//crea la matriz de vista
		D3DXMatrixLookAtLH(&vista, &posCam, &hdveo, &refUp);
		//la de proyeccion
		D3DXMatrixPerspectiveFovLH( &proyeccion, D3DX_PI/4.0, ancho / alto, 0.01f, 1000.0f );
		//las transpone para acelerar la multiplicacion
		D3DXMatrixTranspose( &vista, &vista );
		D3DXMatrixTranspose( &proyeccion, &proyeccion );

		D3DXVec3Normalize(&refUp, &refUp);

		refFront = D3DXVECTOR3(target.x - eye.x, target.y - eye.y, target.z - eye.z);
		D3DXVec3Normalize(&refFront, &refFront);

		D3DXVec3Cross(&refRight, &refFront, &refUp);
		D3DXVec3Normalize(&refRight, &refRight);
		
	}

	D3DXMATRIX UpdateCam(float vel, float arriaba, float izqder, int TipoCam)
	{
		posCamPast = posCam;
		D3DXVECTOR4 tempo;
		D3DXQUATERNION quatern; //quaternion temporal para la camara
		D3DXMATRIX giraUp, giraRight; //matrices temporales para los giros

		//creamos al quaternion segun el vector up
		D3DXQuaternionRotationAxis(&quatern, &refUp, izqder); 
		//lo normalizamos para que no acumule error
		D3DXQuaternionNormalize(&quatern, &quatern);
		//creamos la matriz de rotacion basados en el quaternion
		D3DXMatrixRotationQuaternion(&giraUp, &quatern);

		//transformamos a los vectores ded la camara
		D3DXVec3Transform(&tempo, &refFront, &giraUp);
		//como el resultado de la operacion anterior es Vec4 lo casteamos para hacerlo vec3
		refFront = (D3DXVECTOR3)tempo;
		//normalizamos para no acumular error
		D3DXVec3Normalize(&refFront, &refFront);
		//Con el vector de referencia y el nuevo front calculamos right de nuevo
		D3DXVec3Cross(&refRight, &refFront, &refUp);

		//una vez calculado right a partir de front y up ahora rotamos sobre right
		//repetimos el procedimiento anterior
		D3DXQuaternionRotationAxis(&quatern, &refRight, arriaba);
		D3DXQuaternionNormalize(&quatern, &quatern);
		D3DXMatrixRotationQuaternion(&giraRight, &quatern);

		D3DXVec3Transform(&tempo, &refFront, &giraRight);
		refFront = (D3DXVECTOR3)tempo;
		D3DXVec3Normalize(&refFront, &refFront);
		

		//ajustamos la matriz de vista con lo obtenido
		posCam += refFront * vel/10.0;
		//posCam3p += refFront * vel / 10.0;

		if(TipoCam == 1)
		{
			hdveo = posCam + refFront;
			D3DXMatrixLookAtLH(&vista, &posCam, &hdveo, &refUp);
		}
		else if (TipoCam == 3)
		{
			hdveo = posCam3p + refFront;
			D3DXMatrixLookAtLH(&vista, &posCam3p, &hdveo, &refUp);
		}
		else 
		{
			hdveo = posCam + refFront;
			D3DXMatrixLookAtLH(&vista, &posCam, &hdveo, &refUp);
		}

		D3DXMatrixTranspose( &vista, &vista );
		return vista;
	}
	~Camara()
	{
	}

	float* getPos() {
		pos[0] = posCam.x;
		pos[1] = posCam.z;
		return pos;
	}

	void RenderReflection(float height)
	{
		D3DXVECTOR3 up, position, lookAt;
		float radians;


		// Setup the vector that points upwards.
		up.x = 0.0f;
		up.y = 1.0f;
		up.z = 0.0f;

		// Setup the position of the camera in the world.
		// For planar reflection invert the Y position of the camera.
		position.x = posCam.x;
		position.y = -posCam.y + (height * 2.0f);
		position.z = posCam.z;

		// Calculate the rotation in radians.
		radians = refUp.y * 0.0174532925f;

		// Setup where the camera is looking.
		lookAt.x = sinf(radians) + posCam.x;
		lookAt.y = position.y;
		lookAt.z = cosf(radians) + posCam.z;

		// Create the view matrix from the three vectors.
		D3DXMatrixLookAtLH(&m_reflectionViewMatrix, &position, &lookAt, &up);

		return;
	}

	D3DXMATRIX GetReflectionViewMatrix()
	{
		return m_reflectionViewMatrix;
	}
};
#endif