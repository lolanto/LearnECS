#include "Vector.h"
#include <mathfu/vector.h>

using MVec3 = mathfu::Vector<float, 3>;

Vector3::Vector3(float x, float y, float z) {
	impl = new MVec3(x, y, z);
}

Vector3::~Vector3() {
	if (impl) delete reinterpret_cast<MVec3*>(impl);
}

const Vector3 & Vector3::operator=(const Vector3 & rhs)
{
	if (impl) delete reinterpret_cast<MVec3*>(impl);
	MVec3* ptr = reinterpret_cast<MVec3*>(rhs.impl);
	impl = new MVec3(*ptr);
	return *this;
}

const Vector3& Vector3::operator=(Vector3&& rhs) {
	if (impl) delete reinterpret_cast<MVec3*>(impl);
	impl = rhs.impl;
	rhs.impl = nullptr;
	return *this;
}

Vector3::Vector3(const Vector3& rhs) {
	if (impl) delete reinterpret_cast<MVec3*>(impl);
	MVec3* ptr = reinterpret_cast<MVec3*>(rhs.impl);
	impl = new MVec3(*ptr);
}

Vector3::Vector3(Vector3&& rhs) {
	if (impl) delete reinterpret_cast<MVec3*>(impl);
	impl = rhs.impl;
	rhs.impl = nullptr;
}

float& Vector3::X() { return reinterpret_cast<MVec3*>(impl)->x; }
float& Vector3::Y() { return reinterpret_cast<MVec3*>(impl)->y; }
float& Vector3::Z() { return reinterpret_cast<MVec3*>(impl)->z; }

float Vector3::X() const { return reinterpret_cast<MVec3*>(impl)->x; }
float Vector3::Y() const { return reinterpret_cast<MVec3*>(impl)->y; }
float Vector3::Z() const { return reinterpret_cast<MVec3*>(impl)->z; }