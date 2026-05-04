#pragma once
#include "Shapes.h"

/* ласс, представл€ющий преобразование координат */
class CTransform {
public:
	CTransform();
	Point<double> operator()(const Point<double>&);
	Segment<double> operator()(const Segment<double>&);
	Circle<double> operator()(const Circle<double>&);
};