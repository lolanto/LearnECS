#pragma once
class Entity;
class System {
public:
	System() = default;
	virtual ~System() = default;
	virtual bool operator()(const Entity&) = 0;
};