#pragma once

// column first!
class Matrix4x4 {
public:
	Matrix4x4();
	Matrix4x4(float data[16]);
	~Matrix4x4();
	Matrix4x4(const Matrix4x4&);
	Matrix4x4(Matrix4x4&&);
	const Matrix4x4& operator=(const Matrix4x4& rhs);
	const Matrix4x4& operator=(Matrix4x4&& rhs);
	float& operator[](const size_t& pos);
	float operator[](const size_t& pos) const;
private:
	void* impl = nullptr;
};