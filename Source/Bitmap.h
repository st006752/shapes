#pragma once 
#include <fstream>
#include <cstdint>
#include "Matrix.h"
#include "Storage.h"

class Bitmap {
public:
  Bitmap(size_t r, size_t c): matrix_(r, c) {}

  bool Get(size_t r, size_t c);

  void Set(size_t r, size_t c, bool state) {
    matrix_.set(r, c, state);
  }

  void Save(const char* filename);
  void Load(const char *filename);

private:
	Matrix matrix_;
};
