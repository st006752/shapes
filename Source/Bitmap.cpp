#include "Bitmap.h"
#include "Matrix.h"
#include <fstream>

Bitmap::Bitmap(size_t r, size_t c): matrix_(Matrix(r, c)) {}

bool Bitmap::Get(size_t r, size_t c) {
	return matrix_.get(r, c);
}

void Bitmap::Set(size_t r, size_t c, bool state) {
	return matrix_.set(r, c, state);
}

void Bitmap::Save(const char* filename) {
	std::ofstream out;
    out.open(filename);
	if (!out.is_open()) {
		throw out.exceptions();
	}
	size_t r = matrix_.rows();
	size_t c = matrix_.cols();
	for (size_t y = 0; y < r; ++y) {
		for (size_t x = 0; x < c; ++x) {
			out << matrix_.get(y, x);
		}
	}
}