#pragma once
#include "CID.h"
class Component {
public:
	Component(CID::ID id) : CID(id) {}
	virtual ~Component() = default;
	const CID::ID CID;
};