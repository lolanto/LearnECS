#pragma once
#include "CID.h"
class Component {
public:
	Component(COMID id) : CID(id) {}
	virtual ~Component() = default;
	const COMID CID;
};