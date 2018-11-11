#pragma once
#include "Math/Vector3.h"
struct Ray {
	unsigned int  u = 0, v = 0;
	float r = .0f, g = .0f, b = .0f;
	float attR = 1.0f, attG = 1.0f, attB = 1.0f;
	float ior = 1.0f; // index of refraction of this ray
	Vector3 origin, direction;
	char live = 10;
};

