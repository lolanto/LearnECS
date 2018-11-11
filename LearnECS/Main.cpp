#include <iostream>
#include "Components/PositionCMP.h"
#include "Components/CollidorCMP.h"
#include "Components/MaterialCMP.h"
#include "Components/CameraCMP.h"
#include "Systems/CollidorSys.h"
#include "Systems/MaterialSys.h"
#include "Entity.h"
#include "Universe.h"
using namespace std;

const unsigned int G_WIDTH = 100;
const unsigned int G_HEIGHT = 100;

int main() {
	Film cFilm(G_WIDTH, G_HEIGHT);
	Lens cLens(1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
	Position cPos(0.0f, 0.0f, 0.0f);
	Entity camera(CID::C_FILM, &cFilm, CID::C_LENS, &cLens,
		CID::C_POSITION, &cPos);
	system("pause");
	return 0;
}