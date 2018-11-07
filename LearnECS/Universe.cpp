#include "Universe.h"
#include "Presenter.h"
#include "Entity.h"
#include "Systems/System.h"
#include "Environment.h"

Universe& Universe::InsertRay(Ray r) {
	m_rays.push_back(r);
	return *this;
}

void Universe::SetPresenter(Presenter* p) {
	m_pst = p;
}

void Universe::Run() {
	if (!m_pst) return; // have not setup presenter yet
	while (!m_rays.empty()) {
		Ray ray = (*m_rays.end());
		m_rays.pop_back();
		if (ray.live < 0) continue;
		if (ray.live == 0) {
			m_pst->SetColor(ray.u, ray.v, ray.r, ray.g, ray.b);
			continue;
		}
		Environment env(&ray);
		for (const auto& e_iter : m_es) {
			for (const auto& e_colSys : m_colSys) {
				if ((*e_colSys)(*e_iter, env)) {
					env.hitEntity = e_iter;
					break;
				}
			}
		}
		if (!env.hitEntity) { // 光路离开场景
			m_pst->SetColor(ray.u, ray.v, ray.r, ray.g, ray.b);
		}
		else { // 光路与物体相交
			for (const auto& e_matSys : m_matSys) {
				if ((*e_matSys)((*env.hitEntity), env)) break; // 产生新光路
			}
		}
	}
}

Universe& Universe::InsertEntity(Entity* e) { m_es.push_back(e); return *this; }
Universe& Universe::InsertCollidorSystem(System* s) { m_colSys.push_back(s); return *this; }
Universe& Universe::InsertMaterialSystem(System* s) { m_matSys.push_back(s); return *this; }
