#include "Vector3.h"
#include <mathfu/vector.h>

using MVec3 = mathfu::Vector<float, 3>;

Vector3::Vector3(float x, float y, float z) {
	impl = new MVec3(x, y, z);
}

Vector3::Vector3(void* data) : impl(data) {}

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

float& Vector3::operator[](const size_t& pos) {
	assert(pos >= 0 && pos < 3);
	return (*reinterpret_cast<MVec3*>(impl))[pos];
}

float Vector3::operator[](const size_t& pos) const {
	assert(pos >= 0 && pos < 3);
	return (*reinterpret_cast<MVec3*>(impl))[pos];
}

Vector3 Vector3::operator-(const Vector3& rhs) const {
	MVec3* lptr = reinterpret_cast<MVec3*>(impl);
	MVec3* rptr = reinterpret_cast<MVec3*>(rhs.impl);
	MVec3 res = (*lptr) - (*rptr);
	return Vector3(new MVec3(res));
}

Vector3 Vector3::operator+(const Vector3& rhs) const {
	MVec3* lptr = reinterpret_cast<MVec3*>(impl);
	MVec3* rptr = reinterpret_cast<MVec3*>(rhs.impl);
	MVec3 res = (*lptr) +(*rptr);
	return Vector3(new MVec3(res));
}

Vector3 Vector3::operator*(const float& rhs) const {
	MVec3* ptr = reinterpret_cast<MVec3*>(impl);
	return Vector3(new MVec3((*ptr) * rhs));
}

Vector3 Vector3::operator/(const float& rhs) const {
	MVec3* ptr = reinterpret_cast<MVec3*>(impl);
	return Vector3(new MVec3((*ptr) / rhs));
}

float Vector3::Length() const {
	MVec3* ptr = reinterpret_cast<MVec3*>(impl);
	return ptr->Length();
}

// static function -----------------------------------------

Vector3 Vector3::Normalize(const Vector3& rhs) {
	MVec3* v = reinterpret_cast<MVec3*>(rhs.impl);
	MVec3* r = new MVec3(*v);
	r->Normalize();
	return Vector3(r);
}

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs) {
	MVec3* lptr = reinterpret_cast<MVec3*>(lhs.impl);
	MVec3* rptr = reinterpret_cast<MVec3*>(rhs.impl);
	return mathfu::DotProductHelper(*lptr, *rptr);
}

Vector3 operator*(const float& lhs, const Vector3& rhs) {
	MVec3* ptr = reinterpret_cast<MVec3*>(rhs.impl);
	return Vector3(new MVec3((*ptr) * lhs));
}

Vector3 Vector3::Reflect(const Vector3& vi, const Vector3& n) {
	MVec3* idt = reinterpret_cast<MVec3*>(vi.impl);
	MVec3* nor = reinterpret_cast<MVec3*>(n.impl);
	float c = mathfu::DotProductHelper((*idt), (*nor));
	MVec3 d = (*nor) * (-2 * c);
	d = d + (*idt);
	return Vector3(new MVec3(d));
}