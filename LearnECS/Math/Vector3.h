#pragma once

class Vector3 {
public:
	static Vector3 Normalize(const Vector3& rhs);
public:
	Vector3(float x = .0f, float y = .0f, float z = .0f);
	Vector3(void* data);
	Vector3(const Vector3&);
	Vector3(Vector3&&);
	~Vector3();
	const Vector3& operator=(const Vector3&);
	const Vector3& operator=(Vector3&&);
	float& operator[](const size_t& pos);
	float operator[] (const size_t& pos) const;
	float& X();
	float& Y();
	float& Z();
	float X() const;
	float Y() const;
	float Z() const;

private:
	void* impl = nullptr;
};