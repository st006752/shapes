#pragma once
#include "Shapes.h"

/* ласс, представл€ющий преобразование координат */
class CTransform {
public:
	CTransform(const Rect<double>& originalRect, Rect<double>& destRect);
	Point<double> operator()(const Point<double>&);
	Segment<double> operator()(const Segment<double>&);
	Circle<double> operator()(const Circle<double>&);
private:
	double alphaX_ = 0.0;
	double alphaY_ = 0.0;
	double betaX_ = 0.0;
	double betaY_ = 0.0;
};