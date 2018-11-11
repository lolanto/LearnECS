#include <iostream>
#include "Components/PositionCMP.h"
#include "Components/CollidorCMP.h"
#include "Components/MaterialCMP.h"
#include "Components/CameraCMP.h"
#include "Systems/CollidorSys.h"
#include "Systems/MaterialSys.h"
#include "Systems/CameraSys.h"
#include "Entity.h"
#include "Universe.h"
using namespace std;

const unsigned int G_WIDTH = 480;
const unsigned int G_HEIGHT = 320;

int main() {
	SimpleCameraSys scs;
	BMPDevelopFilmSys bdfs;
	SphereCollidorSystem scsys;
	PlaneCollidorSystem pcs;
	LuminousMaterialSys lms;
	DiffuseMaterialSys dms;
	Film cFilm(G_WIDTH, G_HEIGHT);
	Lens cLens(1.0f, (float)(G_WIDTH) / (float)(G_HEIGHT), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
	Position cPos(0.0f, 0.0f, 0.0f);
	Entity camera(CID::C_FILM, &cFilm, CID::C_LENS, &cLens,
		CID::C_POSITION, &cPos);

	Position spherePos(0.0f, 0.0f, 10.0f);
	SphereCollidor sc(3.0f);
	LuminousMaterial lm(.5f, .2f, .1f);
	Entity sphere(CID::C_POSITION, &spherePos,
		CID::C_SPHERE_COL, &sc,
		CID::C_LUMINOUS_MAT, &lm);

	PlaneCollidor pc(4, 4, 0, 1.0f, 0, 0);
	Position pp(0.0f, -3.0f, 10.0f);
	DiffuseMaterial dm(1.0f, 1.0f, 1.0f);
	Entity plane(CID::C_POSITION, &pp,
		CID::C_PLANE_COL, &pc,
		CID::C_DIFFUSE_MAT, &dm);

	Universe& use = Universe::GetInstance();
	use.InsertEntity(&sphere)
		.InsertEntity(&plane);

	use.InsertMaterialSystem(&lms)
		.InsertMaterialSystem(&dms);

	use.InsertCollidorSystem(&scsys)
		.InsertCollidorSystem(&pcs);

	use.SetCamera(&camera, &scs);
	use.InsertPostProcessSystem(&bdfs);

	use.Run();
	use.PostProcess();
	system("pause");
	return 0;
}