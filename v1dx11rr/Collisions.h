

class Collider
{
public:
	float IsCollision(float xCamera, float zCamera, float xObject, float zObject) {
		float Collision = ((zCamera - zObject) / (xCamera - xObject)) * (xObject - xCamera) - xObject + xCamera;
		return Collision;
	}
};
