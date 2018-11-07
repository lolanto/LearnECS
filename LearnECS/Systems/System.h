#pragma once
class Entity;
class Environment;
class System {
public:
	System() = default;
	virtual ~System() = default;
	virtual bool operator()(const Entity&, Environment&) = 0;
};