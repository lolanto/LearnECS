#include "../Entity.h"
#include "../Environment.h"
#include "../Components/CollidorCMP.h"
#include "../Components/PositionCMP.h"
#include "CollidorSys.h"
#include <math.h>

bool SphereCollidorSystem::operator()(const Entity& ent) {
	Position* p = reinterpret_cast<Position*>(ent(CID::C_POSITION));
	SphereCollidor* sc = reinterpret_cast<SphereCollidor*>(ent(CID::C_SPHERE_COL));
	if (!p || !sc) return false;
	const Ray* r = Environment::GetInstance().curRay;
	Vector3 x = r->origin - p->pos;
	float b = 2 * Vector3::Dot(x, r->direction);
	float c = Vector3::Dot(x, x) - sc->radius * sc->radius;
	float desc = b * b - 4 * c;
	if (desc < 0) return false;
	desc = sqrtf(desc);
	float far = (-b + desc) / 2.0f;
	float near = (-b - desc) / 2.0f;
	
	bool res = far >= 0 || near >= 0;
	if (res) {
		if (near > 0)
			sc->hitPos = r->origin + r->direction * near;
		else
			sc->hitPos = r->origin + r->direction * far;
		sc->hitNor = Vector3::Normalize(p->pos - sc->hitPos);
	}
	return res;
}