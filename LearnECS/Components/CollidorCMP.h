#pragma once
#include "Component.h"

class SphereCollidor : public Component{
public:
	SphereCollidor(float radius)
		: radius(radius), Component(CID::C_SPHERE_COL) {}
	virtual ~SphereCollidor() = default;

	const float radius = 0.0f;
};

class PlaneCollidor : public Component {
public:
	PlaneCollidor(float width, float height,
		float ox, float oy, float oz, float rotate)
		: width(width), height(height),
		normal(Vector3::Normalize(Vector3(ox, oy, oz))),
		front(Vector3::Cross(Vector3(cosf(rotate), 0.0f, sinf(rotate)), normal)),
		left(Vector3::Cross(normal, front)),
		Component(CID::C_PLANE_COL){}

	const float width;
	const float height;
	const Vector3 normal;
	const Vector3 front; // direction of height
	const Vector3 left; // direction of width
};
