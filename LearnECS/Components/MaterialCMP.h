#pragma once
#include "Component.h"

class LuminousMaterial : public Component {
public:
	LuminousMaterial(float r = .0f, float g = .0f, float b = .0f)
		:Component(CID::C_LUMINOUS_MAT), r(r), g(g), b(b) {}
	~LuminousMaterial() = default;
public:
	const float r = 0.0f, g = 0.0f, b = 0.0f;
};

class DiffuseMaterial : public Component {
public:
	DiffuseMaterial(float r = .0f, float g = .0f, float b = .0f)
		:Component(CID::C_DIFFUSE_MAT),
		r(r), g(g), b(b) {}
	~DiffuseMaterial() = default;
public:
	const float r = 0.0f, g = 0.0f, b = 0.0f;
};
