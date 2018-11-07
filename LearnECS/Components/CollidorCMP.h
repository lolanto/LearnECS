#pragma once
#include "Component.h"

class SphereCollidor : public Component{
public:
	SphereCollidor(float radius)
		: radius(radius), Component(CID::C_SPHERE_COL) {}
	virtual ~SphereCollidor() = default;

	const float radius = 0.0f;
};
