#include "Universe.h"
#include "Entity.h"
#include "Systems/System.h"
#include "Environment.h"
#include "Systems/CameraSys.h"
#include "Components/CameraCMP.h"

Universe& Universe::InsertRay(Ray r) {
	m_rays.push_back(r);
	return *this;
}

void Universe::Run() {
	if (!m_cam || !m_camSys) return; // have not setup presenter yet
	Film* tf = reinterpret_cast<Film*>((*m_cam)(CID::C_FILM));
	Environment tempEnv(nullptr);
	while ((*m_camSys)(*m_cam, tempEnv)) {
		while (!m_rays.empty()) {
			Ray ray = m_rays.back();
			m_rays.pop_back();
			if (ray.live < 0) continue;
			if (ray.live == 0) {
				auto iter = (*tf)(ray.u, ray.v);
				iter.r() += ray.r;
				iter.g() += ray.g;
				iter.b() += ray.b;
				iter.a() += 1.0f;
				continue;
			}
			Environment env(&ray);
			for (const auto& e_iter : m_es) {
				for (const auto& e_colSys : m_colSys) {
					if ((*e_colSys)(*e_iter, env)) {
						env.hitEntity = e_iter;
					}
				}
			}
			if (!env.hitEntity) { // 光路离开场景
				auto iter = (*tf)(ray.u, ray.v);
				iter.r() += ray.r;
				iter.g() += ray.g;
				iter.b() += ray.b;
				iter.a() += 1.0f;
			}
			else { // 光路与物体相交
				for (const auto& e_matSys : m_matSys) {
					if ((*e_matSys)((*env.hitEntity), env)) break; // 产生新光路
				}
			}
		}
	}
}

void Universe::PostProcess() {
	if (!m_cam) return;
	Environment tempEnv(nullptr);
	for (auto iter : m_postProSys)
		(*iter)(*m_cam, tempEnv);
}

void Universe::SetCamera(Entity* camera, System* camSys) {
	m_cam = camera;
	m_camSys = camSys;
}
Universe& Universe::InsertEntity(Entity* e) { m_es.push_back(e); return *this; }
Universe& Universe::InsertCollidorSystem(System* s) { m_colSys.push_back(s); return *this; }
Universe& Universe::InsertMaterialSystem(System* s) { m_matSys.push_back(s); return *this; }

Universe& Universe::InsertPostProcessSystem(PostProcessSys* pSys) {
	m_postProSys.push_back(pSys);
	return *this;
}
