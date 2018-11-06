#pragma once
#include "Ray.h"

class Environment {
public:
	static Environment& GetInstance() {
		static Environment _ins;
		return _ins;
	}
public:
	const Ray* curRay = nullptr;
private:
	Environment() = default;
};