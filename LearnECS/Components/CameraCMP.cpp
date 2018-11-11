#include "CameraCMP.h"
#include <assert.h>

Film::FilmIterator Film::FilmIterator::operator+(unsigned offset) const {
	assert(curPos + offset < filmSize);
	FilmIterator ret = *this;
	ret.dataPtr += offset * 4;
	ret.curPos += offset;
	return ret;
}

Film::FilmIterator Film::FilmIterator::operator-(unsigned offset) const {
	assert(curPos + offset >= 0);
	FilmIterator ret = *this;
	ret.dataPtr -= offset * 4;
	ret.curPos -= offset;
	return ret;
}

Film::FilmIterator& Film::FilmIterator::operator++() {
	assert(curPos + 1 <= filmSize);
	curPos += 1;
	dataPtr += 4;
	return *this;
}

Film::FilmIterator Film::FilmIterator::operator++(int) {
	assert(curPos + 1 < filmSize);
	FilmIterator ret = *this;
	curPos += 1;
	dataPtr += 4;
	return ret;
}

Film::FilmIterator Film::FilmIterator::operator*() const {
	return *this;
}

bool Film::FilmIterator::operator==(const Film::FilmIterator& rhs) const {
	return dataPtr == rhs.dataPtr && curPos == rhs.curPos && filmSize == rhs.filmSize;
}

bool Film::FilmIterator::operator!=(const Film::FilmIterator& rhs) const {
	return dataPtr != rhs.dataPtr || curPos != rhs.curPos || filmSize != rhs.filmSize;
}

Film::FilmIterator Film::operator()(int u, int v) {
	assert(u >= 0 && u < Width && v >= 0 && v < Height);
	return iter_begin + u + v * Width;
}

Film::FilmIterator Film::begin() {
	return iter_begin;
}

Film::FilmIterator Film::end() {
	return iter_end;
}