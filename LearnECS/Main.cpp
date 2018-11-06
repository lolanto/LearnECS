#include <iostream>
#include "Components/PositionCMP.h"
#include "Components/CollidorCMP.h"
#include "Systems/CollidorSys.h"
#include "Entity.h"
#include "Environment.h"
#include "Ray.h"
using namespace std;

SphereCollidorSystem scs;

int main() {
	Ray r;
	Environment::GetInstance().curRay = &r;
	r.direction = Vector3::Normalize(Vector3(0, 0, 1));
	SphereCollidor sc(2.0f);
	Position p(0, 0, 0);
	
	Entity e(CID::C_POSITION, &p, CID::C_SPHERE_COL, &sc);
	scs(e);
	cout << sc.hitPos[0] << ' ' << sc.hitPos[1] << ' ' << sc.hitPos[2];
	system("pause");
	return 0;
}