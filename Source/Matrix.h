#include <stddef.h>

class Matrix {
    bool **array_;
    size_t cols_;
    size_t rows_;
public:
    Matrix(size_t height, size_t width);

    ~Matrix();

    bool get(size_t row, size_t col);
};
