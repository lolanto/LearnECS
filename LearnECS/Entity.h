#pragma once
#include <map>

class Component;

using UINT = unsigned int;
class Entity {
public:
	Entity(const UINT id, Component* c) {
		COMS.insert(std::make_pair(id, c));
	}
	Entity() = default;
	template<typename T1 = const UINT, typename T2 = Component*, class ...args>
	Entity(T1 id, T2 c, args... params)
		: Entity(params...) {
		COMS.insert(std::make_pair(id, c));
	}
public:
	UINT ID;
	Component* operator()(const UINT&) const;
	Component* Insert(const UINT&, Component*);
private:
	std::map<const UINT, Component*> COMS;
};