#pragma once

class Vector3 {
public:
	static Vector3 Normalize(const Vector3& rhs);
	static float Dot(const Vector3& lhs, const Vector3& rhs);
	// vi: incident vector, point to normal
	// n: normal of the surface
	static Vector3 Reflect(const Vector3& vi, const Vector3& n);
	static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
public:
	Vector3(float x = .0f, float y = .0f, float z = .0f);
	Vector3(void* data);
	Vector3(const Vector3&);
	Vector3(Vector3&&);
	~Vector3();
	const Vector3& operator=(const Vector3&);
	const Vector3& operator=(Vector3&&);
	Vector3 operator-(const Vector3& rhs) const;
	Vector3 operator+(const Vector3& rhs) const;
	Vector3 operator*(const float& rhs) const;
	Vector3 operator/(const float& rhs) const;
	friend Vector3 operator*(const float& lhs, const Vector3& rhs);
	float& operator[](const size_t& pos);
	float operator[] (const size_t& pos) const;

	float Length() const;

public:
	void Print() const;
private:
	void* impl = nullptr;
};