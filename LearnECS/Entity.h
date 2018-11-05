#pragma once
#include <map>

class Component;

using UINT = unsigned int;
class Entity {
public:
	template<const UINT, Component*, class ...args>
	Entity(const UINT id, Component* c, args... params)
		: Entity(params) {
		COMS.insert(std::make_pair(id, c));
	}
	Entity(const UINT id, Component* c) {
		COMS.insert(std::make_pair(id, c));
	}
	Entity() = default;
public:
	UINT ID;
	Component* operator()(const UINT);
	Component* Insert(const UINT, Component*);
private:
	std::map<const UINT, Component*> COMS;
};