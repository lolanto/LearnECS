#include "CameraSys.h"
#include "../Entity.h"
#include "../Environment.h"
#include "../Components/CameraCMP.h"
#include "../Components/PositionCMP.h"

bool SimpleCameraSys::operator()(const Entity& ent, Environment& env) {
	Lens* ls = reinterpret_cast<Lens*>(ent(CID::C_LENS));
	if (!ls) return false;
	Film* fm = reinterpret_cast<Film*>(ent(CID::C_FILM));
	if (!fm) return false;
	Position* p = reinterpret_cast<Position*>(ent(CID::C_POSITION));
	if (!p) return false;
	for (unsigned i = 0; i < fm->Height; ++i) {
		for (unsigned j = 0; j < fm->Width; ++j) {

		}
	}
}
