#include "Matrix4x4.h"
#include <mathfu/matrix.h>

using MMat4x4 = mathfu::Matrix<float, 4, 4>;

Matrix4x4::Matrix4x4(float data[16]) {
	impl = new MMat4x4(data);
}

Matrix4x4::Matrix4x4() {
	impl = new MMat4x4(0.0f);
}

Matrix4x4::~Matrix4x4() {
	if (impl) delete reinterpret_cast<MMat4x4*>(impl);
}

Matrix4x4::Matrix4x4(const Matrix4x4& rhs) {
	if (impl) delete reinterpret_cast<MMat4x4*>(impl);
	impl = new MMat4x4(*(reinterpret_cast<MMat4x4*>(rhs.impl)));
}

Matrix4x4::Matrix4x4(Matrix4x4&& rhs) {
	if (impl) delete reinterpret_cast<MMat4x4*>(impl);
	impl = rhs.impl;
	rhs.impl = nullptr;
}

const Matrix4x4& Matrix4x4::operator=(const Matrix4x4& rhs) {
	if (impl) delete reinterpret_cast<MMat4x4*>(impl);
	impl = new MMat4x4(*(reinterpret_cast<MMat4x4*>(rhs.impl)));
	return *this;
}

const Matrix4x4& Matrix4x4::operator=(Matrix4x4&& rhs) {
	if (impl) delete reinterpret_cast<MMat4x4*>(impl);
	impl = rhs.impl;
	rhs.impl = nullptr;
	return (*this);
}

// column first;
float& Matrix4x4::operator[](const size_t& pos) {
	assert(pos >= 0 && pos < 16);
	return (*(reinterpret_cast<MMat4x4*>(impl)))[pos];
}

float Matrix4x4::operator[](const size_t& pos) const {
	assert(pos >= 0 && pos < 16);
	return (*(reinterpret_cast<MMat4x4*>(impl)))[pos];
}