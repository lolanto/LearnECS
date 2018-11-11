#include "MaterialSys.h"
#include "../Entity.h"
#include "../Components/MaterialCMP.h"
#include "../Ray.h"
#include "../Environment.h"
bool LuminousMaterialSys::operator()(const Entity& ent, Environment& env) {
	LuminousMaterial* lm = reinterpret_cast<LuminousMaterial*>(ent(CID::C_LUMINOUS_MAT));
	if (!lm) return false;
	Ray* r = env.GetRay();
	// 能量更改
	r->r += r->attR * lm->r;
	r->g += r->attG * lm->g;
	r->b += r->attB * lm->b;
	--r->live;
	if (r->live == 0) return true;
	// 更改新光路
	Ray reflectPath = (*r);
	reflectPath.origin = env.HitPos;
	reflectPath.direction = Vector3::Reflect(r->direction, env.HitNor);
	env.InsertRay(reflectPath);
	// 结束该光路
	r->live = -1;
	return true;
}

bool DiffuseMaterialSys::operator()(const Entity& ent, Environment& env) {
	DiffuseMaterial* dm = reinterpret_cast<DiffuseMaterial*>(ent(CID::C_DIFFUSE_MAT));
	if (!dm) return false;
	Ray* r = env.GetRay();
	--r->live;
	if (r->live == 0) return true;
	r->attR *= dm->r;
	r->attG *= dm->g;
	r->attB *= dm->b;
	// 更改新光路
	Ray reflectPath = (*r);
	reflectPath.origin = env.HitPos;
	reflectPath.direction = Vector3::Reflect(r->direction, env.HitNor);
	env.InsertRay(reflectPath);
	// 结束该光路
	r->live = -1;
	return true;
}
