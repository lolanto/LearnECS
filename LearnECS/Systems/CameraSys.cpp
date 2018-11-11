#include "CameraSys.h"
#include "../Entity.h"
#include "../Environment.h"
#include "../Components/CameraCMP.h"
#include "../Components/PositionCMP.h"
#include <random>
#include "../BMPPresenter/BMPPresenter.h"

bool SimpleCameraSys::operator()(const Entity& ent, Environment& env) {
	static Lens* ls = reinterpret_cast<Lens*>(ent(CID::C_LENS));
	if (!ls) return false;
	static Film* fm = reinterpret_cast<Film*>(ent(CID::C_FILM));
	if (!fm) return false;
	static Position* p = reinterpret_cast<Position*>(ent(CID::C_POSITION));
	if (!p) return false;
	static Vector3 left = Vector3::Cross(ls->Up, ls->Orientation);
	static Vector3 basePoint = p->pos + ls->Orientation * ls->Focus;
	static float deltaX = (2.0f * ls->Aspect) / fm->Width;
	static float deltaY = 2.0f / fm->Height;

	static float minDelta = deltaX > deltaY ? deltaY : deltaX;
	static std::random_device rd;
	static std::uniform_real_distribution<float> urd(-(minDelta) / 10.0f, minDelta / 10.0f);

	//for (unsigned i = 0; i < fm->Height; ++i) {
	//	for (unsigned j = 0; j < fm->Width; ++j) {
	//		Ray nr;
	//		nr.u = j; nr.v = i;
	//		nr.origin = p->pos;
	//		nr.direction = Vector3::Normalize(basePoint + left * (j * deltaX + urd(rd) - ls->Aspect) + ls->Up * (1.0 - i * deltaY + urd(rd)) - nr.origin);
	//		env.InsertRay(nr);
	//		nr.direction = Vector3::Normalize(basePoint + left * (j * deltaX + urd(rd) - ls->Aspect) + ls->Up * (1.0 - i * deltaY + urd(rd)) - nr.origin);
	//		env.InsertRay(nr);
	//	}
	//}
	//return true;
	static unsigned i = 0;
	static unsigned j = 0;
	if (i < fm->Height) {
		if (j < fm->Width) {
			Ray nr;
			nr.u = j; nr.v = i;
			nr.origin = p->pos;
			nr.direction = Vector3::Normalize(basePoint + left * (j * deltaX + urd(rd) - ls->Aspect) + ls->Up * (1.0 - i * deltaY + urd(rd)) - nr.origin);
			env.InsertRay(nr);
			nr.direction = Vector3::Normalize(basePoint + left * (j * deltaX + urd(rd) - ls->Aspect) + ls->Up * (1.0 - i * deltaY + urd(rd)) - nr.origin);
			env.InsertRay(nr);
			++j;
			return true;
		}
		else {
			j = 0;
			++i;
			return true;
		}
	}
	else
		return false;
}

bool BMPDevelopFilmSys::operator()(const Entity& ent, Environment& env) {
	Film* f = reinterpret_cast<Film*>(ent(CID::C_FILM));
	if (!f) return false;
	BMPPresenter& pst = BMPPresenter::GetInstance();
	auto iter = f->begin();
	pst.Setup(f->Width, f->Height);
	for (size_t v = 0; v < f->Height; ++v)
		for (size_t u = 0; u < f->Width; ++u, ++iter) {
			pst.SetColor(u, v, iter.r() / iter.a(), iter.g() / iter.a(), iter.b() / iter.a());
		}
	pst.Present();
	return true;
}
