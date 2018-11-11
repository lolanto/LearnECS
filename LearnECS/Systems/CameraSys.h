#pragma once
#include "System.h"

class SimpleCameraSys : public System {
public:
	bool operator()(const Entity&, Environment&);
};

class PostProcessSys : public System {
public:
	PostProcessSys() = default;
	virtual ~PostProcessSys() = default;
	virtual bool operator()(const Entity&, Environment&) = 0;
};

class BMPDevelopFilmSys : public PostProcessSys {
public:
	bool operator()(const Entity&, Environment&);
};
