#pragma once
#include "Component.h"
#include "../Math/Vector3.h"
class Position : public Component {
public:
	Position(float x = .0f, float y = .0f, float z = .0f)
		:pos(x, y, z), Component(CID::C_POSITION) {}
	virtual ~Position() = default;

	const Vector3 pos;
};