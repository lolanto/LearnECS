#include "CameraSys.h"
#include "../Entity.h"
#include "../Environment.h"
#include "../Components/CameraCMP.h"
#include "../Components/PositionCMP.h"

#include "../BMPPresenter/BMPPresenter.h"

bool SimpleCameraSys::operator()(const Entity& ent, Environment& env) {
	Lens* ls = reinterpret_cast<Lens*>(ent(CID::C_LENS));
	if (!ls) return false;
	Film* fm = reinterpret_cast<Film*>(ent(CID::C_FILM));
	if (!fm) return false;
	Position* p = reinterpret_cast<Position*>(ent(CID::C_POSITION));
	if (!p) return false;
	Vector3 left = Vector3::Dot(ls->Up, ls->Orientation);
	Vector3 basePoint = p->pos + ls->Orientation * ls->Focus;
	float deltaX = (2.0f * ls->Aspect) / fm->Width;
	float deltaY = 2.0f / fm->Height;
	for (unsigned i = 0; i < fm->Height; ++i) {
		for (unsigned j = 0; j < fm->Width; ++j) {
			Ray nr;
			nr.u = j; nr.v = i;
			nr.origin = p->pos;
			nr.direction = Vector3::Normalize(basePoint + left * (i * deltaX - ls->Aspect) + ls->Up * (j * deltaY - 1.0f) - nr.origin);
			env.InsertRay(nr);
		}
	}
	return true;
}

bool BMPDevelopFilmSys::operator()(const Entity& ent, Environment& env) {
	Film* f = reinterpret_cast<Film*>(ent(CID::C_FILM));
	if (!f) return false;
	BMPPresenter& pst = BMPPresenter::GetInstance();
	auto iter = f->begin();
	pst.Setup(f->Width, f->Height);
	for (size_t v = 0; v < f->Height; ++v)
		for (size_t u = 0; u < f->Width; ++u, ++iter)
			pst.SetColor(u, v, iter.r(), iter.g(), iter.b());
	pst.Present();
	return true;
}
