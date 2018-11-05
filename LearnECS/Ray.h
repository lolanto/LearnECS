#pragma once
#include "Math/Vector3.h"
struct Ray {
	unsigned int u, v;
	float r, g, b;
	unsigned char live;
	Vector3 origin, direction;
};
