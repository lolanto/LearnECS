#include <iostream>
#include "Components/PositionCMP.h"
#include "Components/CollidorCMP.h"
#include "Components/MaterialCMP.h"
#include "Systems/CollidorSys.h"
#include "Systems/MaterialSys.h"
#include "Entity.h"
#include "Universe.h"
using namespace std;

SphereCollidorSystem scs;
LuminousMaterialSys lms;
SphereCollidor sc1(2.0f);
LuminousMaterial lm1(1.0f, 1.0f, 1.0f);

int main() {
	Position p;
	Entity e1(CID::C_LUMINOUS_MAT, &lm1,
		CID::C_POSITION, &p,
		CID::C_SPHERE_COL, &sc1);
	Universe::GetInstance().InsertEntity(&e1)
		.InsertCollidorSystem(&scs)
		.InsertMaterialSystem(&lms);

	system("pause");
	return 0;
}