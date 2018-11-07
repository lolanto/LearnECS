#pragma once
#include "Ray.h"
#include <float.h>
class Entity;
class Environment {
public:
	Environment(Ray* ptr) : m_ray(ptr) {}
	Ray* GetRay() { return m_ray; }
	void InsertRay(Ray);
public:
	Vector3 HitPos, HitNor;
	float HitDis = FLT_MAX;
	Entity* hitEntity = nullptr;
private:
	Ray * m_ray = nullptr;
};