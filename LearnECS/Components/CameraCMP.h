#pragma once
#include "../Math/Vector3.h"
#include "Component.h"
#include <memory>

class Film : public Component {
public:
	Film(size_t width, size_t height)
		:Component(CID::C_FILM), Width(width), Height(height) {
		Buffer = new float[Width * Height * 4]; // r, g, b, other data
		memset(Buffer, 0, Width * Height * 4 * sizeof(float));
		iter_begin = FilmIterator(Buffer, 0, Width * Height);
		iter_end = FilmIterator(Buffer + Width * Height * 4, Width * Height, Width * Height);
	}
	~Film() { if (Buffer) delete[] Buffer; }
	const size_t Width;
	const size_t Height;
public:
	class FilmIterator {
		friend Film;
	public:
		float& r() { return dataPtr[0]; }
		float& g() { return dataPtr[1]; }
		float& b() { return dataPtr[2]; }
		float& a() { return dataPtr[3]; }
		FilmIterator operator+(unsigned offset) const;
		FilmIterator operator-(unsigned offset) const;
		FilmIterator& operator++();
		FilmIterator operator++(int);
		bool operator==(const FilmIterator& rhs) const;
		bool operator!=(const FilmIterator& rhs) const;
		FilmIterator operator*() const;
		FilmIterator(float* dp, size_t cp, size_t s)
			: dataPtr(dp), curPos(cp), filmSize(s) {}
	private:
		FilmIterator() = default;
	private:
		float* dataPtr = nullptr;
		size_t curPos = 0;
		size_t filmSize = 0; // width * height
	};
	FilmIterator operator()(int u, int v);
	FilmIterator begin();
	FilmIterator end();
private:
	Film(const Film&) = delete;
	Film(Film&&) = delete;
	const Film& operator=(const Film&) = delete;
	const Film& operator=(Film&&) = delete;
private:
	float* Buffer = nullptr;
	FilmIterator iter_begin;
	FilmIterator iter_end;
};

class Lens : public Component {
public:
	Lens(float f, float aspect, float ox, float oy, float oz,
		float ux, float uy, float uz)
		: Component(CID::C_LENS),
		Focus(f), Aspect(aspect),
		Orientation(Vector3::Normalize(Vector3(ox, oy, oz))),
		Up(Vector3::Normalize(Vector3(ux, uy, uz))) {}
public:
	const Vector3 Orientation;
	const Vector3 Up;
	const float Focus;
	const float Aspect;
};