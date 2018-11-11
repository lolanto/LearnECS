#pragma once
#include "System.h"

class SphereCollidorSystem : public System {
public:
	bool operator()(const Entity&, Environment&);
};

class PlaneCollidorSystem : public System {
public:
	bool operator()(const Entity&, Environment&);
};
