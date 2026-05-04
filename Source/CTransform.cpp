#include <algorithm>

#include "CTransform.h"

CTransform::CTransform(const Rect<double>& originalRect, Rect<double>& destRect) {
	const double originalW = originalRect.width();
	const double originalH = originalRect.height();

	const double destW = destRect.width();
	const double destH = destRect.height();

	const double minSize = 256.0;
	/*
	xdest = alphaX_ * xorig + betaX_;

	destRect.topLeft().x() = alphaX_ * originalRect.topLeft().x() + betaX_;
	destRect.bottomRight().x() = alphaX_ * originalRect.bottomRight().x() + betaX_;
	*/

	alphaX_ = destW / originalW;
	alphaY_ = destH / originalH;

	betaX_ = destRect.topLeft().x() - alphaX_ * originalRect.topLeft().x();
	betaY_ = destRect.topLeft().y() - alphaY_ * originalRect.topLeft().y();

	/*
	alpha_ = 1.0;

	if (w > 0.0 && h > 0.0)
		alpha_ = std::min(screenW / w, screenH / h);
	else if (w > 0.0)
		alpha_ = screenW / w;
	else if (h > 0.0)
		alpha_ = screenH / h;


	double alphaMin = 1.0;
	if (w > 0.0 && h > 0.0)
		alphaMin = std::max(minSize / w, minSize / h);
	else if (w > 0.0)
		alphaMin = minSize / w;
	else
		alphaMin = minSize / h;

	double alphaMax = 1.0;
	if (w > 0.0 && h > 0.0)
		alphaMax = std::min(screenW / w, screenH / h);
	else if (w > 0.0)
		alphaMax = screenW / w;
	else
		alphaMax = screenH / h;

	alpha_ = std::max(alphaMin, std::min(alpha_, alphaMax));;

	betaX_ = destRect.topLeft().x() - originalRect.topLeft().x();
	betaY_ = destRect.topLeft().y() - originalRect.topLeft().y();

	*/
}

Point<double> CTransform::operator()(const Point<double>&orig) {
	Point<double> result( 
		alphaX_*orig.x() + betaX_,
		alphaY_*orig.y() + betaY_);

	return result;
}
Segment<double> CTransform::operator()(const Segment<double>&orig) {
	Segment<double> result;
	result.set_p1((*this)(orig.p1()));
	result.set_p2((*this)(orig.p2()));
	return result;
}

Circle<double> CTransform::operator()(const Circle<double>&) {
	Circle<double> result;

	return result;
}