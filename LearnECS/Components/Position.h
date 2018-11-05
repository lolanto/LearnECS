#pragma once
#include "Component.h"

class Position : public Component {
public:
	Position(float x = .0f, float y = .0f, float z = .0f)
		: x(x), y(y), z(z), Component(CID::C_POSITION) {}
	virtual ~Position() = default;
private:
	float x = 0.0f, y = 0.0f, z = 0.0f;
};