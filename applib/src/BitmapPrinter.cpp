#include "BitmapPrinter.h"



BitmapPrinter::BitmapPrinter(size_t width, size_t height)
{
	bitmap_ = new Bitmap(height, width);
}


BitmapPrinter::~BitmapPrinter()
{
	delete bitmap_;
}

void BitmapPrinter::drawPoint(const Point<double>&pt) {
	bitmap_->Set(
		static_cast<size_t>(pt.x()),
		static_cast<size_t>(pt.y()),
		true
	);
}

void BitmapPrinter::drawSegment(const Segment<double>&seg) {
	int x1 = static_cast<int> (seg.p1().x());
	int y1 = static_cast<int> (seg.p1().y());
	const int x2 = static_cast<int> (seg.p2().x());
	const int y2 = static_cast<int> (seg.p2().y());


	int A, B, sign;
	A = y2 - y1;
	B = x1 - x2;
	if (abs(A) > abs(B))
		sign = 1;
	else
		sign = -1;
	int signa, signb;
	if (A < 0)
		signa = -1;
	else
		signa = 1;
	if (B < 0)
		signb = -1;
	else
		signb = 1;
	int f = 0;
	bitmap_->Set(x1,y1,true);
	int x = x1, y = y1;
	if (sign == -1)
	{
		do {
			f += A * signa;
			if (f > 0)
			{
				f -= B * signb;
				y += signa;
			}
			x -= signb;
			bitmap_->Set(x,y,true);
		} while (x != x2 || y != y2);
	}
	else
	{
		do {
			f += B * signb;
			if (f > 0) {
				f -= A * signa;
				x -= signb;
			}
			y += signa;
			bitmap_->Set(x,y,true);
		} while (x != x2 || y != y2);
	}


	/*
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	bitmap_->Set(x2, y2,true);
	while (x1 != x2 || y1 != y2)
	{
		bitmap_->Set(x1, y1,true);
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
	*/
}

void BitmapPrinter::drawCircle(const Circle<double>&) {

}

void BitmapPrinter::save2File(const char* fileName) {
	bitmap_->Save(fileName);
}
