#pragma once

class Vector3 {
public:
	Vector3(float x = .0f, float y = .0f, float z = .0f);
	Vector3(const Vector3&);
	Vector3(Vector3&&);
	~Vector3();
	const Vector3& operator=(const Vector3&);
	const Vector3& operator=(Vector3&&);
	float& X();
	float& Y();
	float& Z();
	float X() const;
	float Y() const;
	float Z() const;

private:
	void* impl = nullptr;
};