#include "Entity.h"

Component* Entity::operator()(const UINT CID) {
	auto res = COMS.find(CID);
	if (res == COMS.end()) return nullptr;
	return res->second;
}

Component* Entity::Insert(const UINT CID, Component* c) {
	auto res = COMS.find(CID);
	Component* ptr = nullptr;
	if (res != COMS.end()) {
		ptr = res->second;
		res->second = c;
	}
	return ptr;
}