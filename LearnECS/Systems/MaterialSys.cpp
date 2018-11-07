#include "MaterialSys.h"
#include "../Entity.h"
#include "../Components/MaterialCMP.h"
#include "../Ray.h"
#include "../Environment.h"
bool LuminousMaterialSys::operator()(const Entity& ent, Environment& env) {
	LuminousMaterial* lm = reinterpret_cast<LuminousMaterial*>(ent(CID::C_LUMINOUS_MAT));
	if (!lm) return false;
	Ray* r = env.GetRay();
	// ��������
	r->r += r->attenuation * lm->r;
	r->g += r->attenuation * lm->g;
	r->b += r->attenuation * lm->b;
	--r->live;
	if (r->live == 0) return true;
	// �����¹�·
	Ray reflectPath = (*r);
	reflectPath.origin = env.HitPos;
	reflectPath.direction = Vector3::Reflect(r->direction, env.HitNor);
	--reflectPath.live;
	env.InsertRay(reflectPath);
	// �����ù�·
	r->live = -1;
	return true;
}
