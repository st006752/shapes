#include "Bitmap.h"
#include <fstream>

Bitmap::Bitmap(size_t r, size_t c) {
	matrix_ = new Matrix(r, c);
}
Bitmap::Bitmap(const char* filename) {}

Bitmap::~Bitmap() {
	delete matrix_;
}

bool Bitmap::Get(size_t r, size_t c) {
	return matrix_.get(r, c);
}

void Bitmap::Set(size_t r, size_t c, bool state) {
	return matrix_.set(r, c, state);
}

void Bitmap::Save(const char* filename) {
	std::ifstream in;
}