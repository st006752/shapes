#include "Bitmap.h"

Bitmap(size_t r, size_t c);
Bitmap(const char* filename);

~Bitmap();

bool Get(size_t r, size_t c);

void Set(size_t r, size_t c, bool state);

void Save(const char* filename);