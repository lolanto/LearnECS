#pragma once
#include "../Math/Vector3.h"
#include "Component.h"

class Film : public Component {
public:
	Film(float width, float height)
		:Component(CID::C_FILM), Width(width), Height(height) {}
	const float Width;
	const float Height;
};

class Lens : public Component {
public:
	Lens(float f, float aspect, float ox, float oy, float oz,
		float ux, float uy, float uz)
		: Component(CID::C_LENS),
		Focus(f), Aspect(aspect),
		Orientation(ox, oy, oz), Up(ux, uy, uz) {}
public:
	const Vector3 Orientation;
	const Vector3 Up;
	const float Focus;
	const float Aspect;
};