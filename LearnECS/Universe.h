#pragma once
#include "Ray.h"
#include <vector>

class Presenter;
class Entity;
class System;
class Universe {
public:
	static Universe& GetInstance() {
		static Universe _ins;
		return _ins;
	}
public:
	Universe& InsertRay(Ray);
	Universe& InsertEntity(Entity*);
	Universe& InsertCamera(Entity*);
	Universe& InsertCollidorSystem(System*);
	Universe& InsertMaterialSystem(System*);
	void PrepareRay();
	void SetPresenter(Presenter*);
	void Run();
private:
	Universe() = default;
private:
	std::vector<Ray> m_rays;
	std::vector<Entity*> m_es;
	std::vector<System*> m_colSys;
	std::vector<System*> m_matSys;
	Presenter* m_pst = nullptr;
	Entity* m_cam = nullptr;
};