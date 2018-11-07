#include "../Entity.h"
#include "../Environment.h"
#include "../Components/CollidorCMP.h"
#include "../Components/PositionCMP.h"
#include "CollidorSys.h"
#include <math.h>

bool SphereCollidorSystem::operator()(const Entity& ent, Environment& env) {
	Position* p = reinterpret_cast<Position*>(ent(CID::C_POSITION));
	if (!p) return false;
	SphereCollidor* sc = reinterpret_cast<SphereCollidor*>(ent(CID::C_SPHERE_COL));
	if (!sc) return false;
	const Ray* r = env.GetRay();
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
		if (near > 0) {
			if (near < env.HitDis) {
				env.HitDis = near;
				env.HitPos = r->origin + r->direction * near;
				env.HitNor = Vector3::Normalize(p->pos - env.HitPos);
			}
			else
				res = false;
		}
		else {
			if (far < env.HitDis) {
				env.HitDis = far;
				env.HitPos = r->origin + r->direction * far;
				env.HitNor = Vector3::Normalize(p->pos - env.HitPos);
			}
			else
				res = false;
		}
	}
	return res;
}