#include "Environment.h"
#include "Universe.h"
void Environment::InsertRay(Ray r) {
	Universe::GetInstance().InsertRay(r);
}