#pragma once
#include "Component.h"

class Collidor {
public:
	Vector3 hitPos;
	Vector3 hitNor;
	float hitU = 0.0f, hitV = 0.0f;
};

class SphereCollidor : public Component, public Collidor{
public:
	SphereCollidor(float radius)
		: radius(radius), Component(CID::C_SPHERE_COL) {}
	virtual ~SphereCollidor() = default;

	const float radius = 0.0f;
};
