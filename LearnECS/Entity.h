#pragma once
#include "Components/CID.h"
#include <map>

class Component;

using UINT = unsigned int;
class Entity {
public:
	UINT ID;
	Component* operator()(COMID);
private:
	std::map<COMID, Component*> COMS;
};