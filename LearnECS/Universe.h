#pragma once
#include "Ray.h"
#include <vector>

class Presenter;
class Entity;
class System;
class PostProcessSys;
class Universe {
public:
	static Universe& GetInstance() {
		static Universe _ins;
		return _ins;
	}
public:
	Universe& InsertRay(Ray);
	Universe& InsertEntity(Entity*);
	Universe& InsertCollidorSystem(System*);
	Universe& InsertMaterialSystem(System*);
	Universe& InsertPostProcessSystem(PostProcessSys*);
	void SetCamera(Entity*, System*);
	void Run();
	void PostProcess();
private:
	Universe() = default;
private:
	std::vector<Ray> m_rays;
	std::vector<Entity*> m_es;
	std::vector<System*> m_colSys;
	std::vector<System*> m_matSys;
	std::vector<PostProcessSys*> m_postProSys;
	Entity* m_cam = nullptr;
	System* m_camSys = nullptr;
};