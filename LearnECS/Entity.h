#pragma once

class Body;
class Material;

using UINT = unsigned int;
class Entity {
public:
	UINT ID;
	Body* Body_cmp;
	Material* Mat_cmp;
};