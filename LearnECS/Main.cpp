#include <iostream>
#include "Components/Position.h"
#include "Components/Collidor.h"
#include "Entity.h"
using namespace std;
void main() {
	SphereCollidor cs(2.0f);
	Position p;
	Entity e(CID::C_SPHERE_COL, &cs, CID::C_POSITION, &p);
	system("pause");
}