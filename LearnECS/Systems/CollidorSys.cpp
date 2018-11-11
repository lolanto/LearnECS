#include "../Entity.h"
#include "../Environment.h"
#include "../Components/CollidorCMP.h"
#include "../Components/PositionCMP.h"
#include "CollidorSys.h"
#include <math.h>

const float HIT_THRESHOLD = 0.001f; // 避免运算误差，引入碰撞判定的阈值

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
	
	bool res = far >= HIT_THRESHOLD || near >= HIT_THRESHOLD;
	if (res) {
		if (near > 0) {
			if (near < env.HitDis) {
				env.HitDis = near;
				env.HitPos = r->origin + r->direction * near;
				env.HitNor = Vector3::Normalize(env.HitPos - p->pos);
			}
			else
				res = false;
		}
		else {
			if (far < env.HitDis) {
				env.HitDis = far;
				env.HitPos = r->origin + r->direction * far;
				env.HitNor = Vector3::Normalize(env.HitPos - p->pos);
			}
			else
				res = false;
		}
	}
	return res;
}

bool PlaneCollidorSystem::operator()(const Entity& ent, Environment& env) {
	Position* p = reinterpret_cast<Position*>(ent(CID::C_POSITION));
	if (!p) return false;
	PlaneCollidor* pc = reinterpret_cast<PlaneCollidor*>(ent(CID::C_PLANE_COL));
	if (!pc) return false;
	const Ray* r = env.GetRay();
	float dn = Vector3::Dot(r->direction, pc->normal);
	if (dn < HIT_THRESHOLD) return false;
	float pn = Vector3::Dot(p->pos, pc->normal);
	float on = Vector3::Dot(r->origin, pc->normal);
	float t = -(pn - on) / dn; // 为什么要添加个-号？
	if (t > env.HitDis) return false;
	env.HitPos = r->origin + t * r->direction;
	Vector3 offset = env.HitPos - p->pos;
	float dw = Vector3::Dot(offset, pc->left);
	if (fabsf(dw) * 2.0f > pc->width) return false;
	float dh = Vector3::Dot(offset, pc->front);
	if (fabsf(dh) * 2.0f > pc->height) return false;
	env.HitNor = pc->normal;
	env.HitDis = t;
	return true;
}