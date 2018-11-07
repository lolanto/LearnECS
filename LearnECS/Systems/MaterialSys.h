#pragma once
#include "System.h"

class LuminousMaterialSys : public System {
public:
	bool operator()(const Entity&, Environment&);
};
