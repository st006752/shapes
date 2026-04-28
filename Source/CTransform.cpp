#include "CTransform.h"

CTransform::CTransform() {
}

Point<double> CTransform::operator()(const Point<double>&orig) {
	Point<double> result;

	return result;
}
Segment<double> CTransform::operator()(const Segment<double>&) {
	Segment<double> result;

	return result;
}

Circle<double> CTransform::operator()(const Circle<double>&) {
	Circle<double> result;

	return result;
}