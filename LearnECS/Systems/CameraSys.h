#pragma once
#include "System.h"

class SimpleCameraSys : public System {
public:
	bool operator()(const Entity&, Environment&);
};
