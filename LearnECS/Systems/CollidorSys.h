#pragma once
#include "System.h"

class SphereCollidorSystem : public System {
public:
	bool operator()(const Entity&);
};