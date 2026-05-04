#include <iostream>
#include <cmath>

#include <gtest/gtest.h>

#include "../Source/Matrix.h"
#include "../Source/App.h"
#include "../Source/Relations.h"
#include "../Source/Rectangle.h"
#include "../Source/Bitmap.h"
#include "../Source/BitmapPrinter.h"
#include "../Source/CTransform.h"


TEST(PointDistance, SamePoint) {
	App app;
	Identi p1 = app.addObject(PrimitiveType::POINT);

	Point<double>* point = app.findObjectById(p1, app.getPoints());
	point->set_x(0);
	point->set_y(0);

	Storage<Identi> ids;
	ids.addItem(p1);
	ids.addItem(p1);

	PointDistanceRelation relation(Identi(), ids);
	relation.setApp(&app);
	EXPECT_DOUBLE_EQ(relation.measure(), 0.0);
}

TEST(PointDistance, DifferentPoints) {
	App app;
	Identi p1 = app.addObject(PrimitiveType::POINT);
	Identi p2 = app.addObject(PrimitiveType::POINT);

	Point<double>* point1 = app.findObjectById(p1, app.getPoints());
	Point<double>* point2 = app.findObjectById(p2, app.getPoints());
	point1->set_x(-1);
	point1->set_y(-1);
	point2->set_x(2);
	point2->set_y(3);

	Storage<Identi> ids;
	ids.addItem(p1);
	ids.addItem(p2);

	PointDistanceRelation relation(Identi(), ids);
	relation.setApp(&app);
	EXPECT_DOUBLE_EQ(relation.measure(), 5.0);
}

TEST(PointCoincident, SamePoint) {
	App app;
	Identi p1 = app.addObject(PrimitiveType::POINT);

	Point<double>* point = app.findObjectById(p1, app.getPoints());
	point->set_x(0);
	point->set_y(0);

	Storage<Identi> ids;
	ids.addItem(p1);
	ids.addItem(p1);

	PointCoincidentRelation relation(Identi(), ids);
	relation.setApp(&app);
	EXPECT_DOUBLE_EQ(relation.measure(), 0.0);
}

TEST(PointCoincident, DifferentPoints) {
	App app;
	Identi p1 = app.addObject(PrimitiveType::POINT);
	Identi p2 = app.addObject(PrimitiveType::POINT);

	Point<double>* point1 = app.findObjectById(p1, app.getPoints());
	Point<double>* point2 = app.findObjectById(p2, app.getPoints());
	point1->set_x(1);
	point1->set_y(2);
	point2->set_x(4);
	point2->set_y(6);

	Storage<Identi> ids;
	ids.addItem(p1);
	ids.addItem(p2);

	PointCoincidentRelation relation(Identi(), ids);
	relation.setApp(&app);
	double distance = relation.measure();
	EXPECT_DOUBLE_EQ(distance, 5.0);
}

TEST(SegmentVertical, VerticalSegment) {
	App app;
	Identi s1 = app.addObject(PrimitiveType::SEGMENT);

	Segment<double>* segment = app.findObjectById(s1, app.getSegments());
	segment->set_p1(Point<double>(2, 0));
	segment->set_p2(Point<double>(2, 5));

	Storage<Identi> ids;
	ids.addItem(s1);

	SegmentVerticalRelation relation(Identi(), ids);
	relation.setApp(&app);
	EXPECT_DOUBLE_EQ(relation.measure(), 0.0);
}

TEST(SegmentVertical, NonVerticalSegment) {
	App app;
	Identi s1 = app.addObject(PrimitiveType::SEGMENT);

	Segment<double>* segment = app.findObjectById(s1, app.getSegments());
	segment->set_p1(Point<double>(0, 0));
	segment->set_p2(Point<double>(4, 0));

	Storage<Identi> ids;
	ids.addItem(s1);

	SegmentVerticalRelation relation(Identi(), ids);
	relation.setApp(&app);
	EXPECT_DOUBLE_EQ(relation.measure(), 4.0);
}

TEST(SegmentVertical, NegativeDirection) {
	App app;
	Identi s1 = app.addObject(PrimitiveType::SEGMENT);

	Segment<double>* segment = app.findObjectById(s1, app.getSegments());
	segment->set_p1(Point<double>(3, 1));
	segment->set_p2(Point<double>(-2, 7));

	Storage<Identi> ids;
	ids.addItem(s1);

	SegmentVerticalRelation relation(Identi(), ids);
	relation.setApp(&app);
	EXPECT_DOUBLE_EQ(relation.measure(), 5.0);
}


TEST(Rect, Init) {
	using pd = point_coor<double>;
	Rect<double> rect1({ 0.0,0.0 }, { 0.0,0.0 });
	EXPECT_DOUBLE_EQ(rect1.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect1.topLeft().y(), 0.0);
	EXPECT_DOUBLE_EQ(rect1.bottomRight().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect1.bottomRight().y(), 0.0);

	Rect<double> rect2({ 0.0,0.0 }, { 1.0,-1.0 });
	EXPECT_DOUBLE_EQ(rect2.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect2.topLeft().y(), 0.0);
	EXPECT_DOUBLE_EQ(rect2.bottomRight().x(), 1.0);
	EXPECT_DOUBLE_EQ(rect2.bottomRight().y(), -1.0);

	Rect<double> rect3({ 0.0,0.0 }, { 0.0,-1.0 });
	EXPECT_DOUBLE_EQ(rect3.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect3.topLeft().y(), 0.0);
	EXPECT_DOUBLE_EQ(rect3.bottomRight().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect3.bottomRight().y(), -1.0);

	Rect<double> rect4({ 0.0,0.0 }, { 1.0,0.0 });
	EXPECT_DOUBLE_EQ(rect4.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect4.topLeft().y(), 0.0);
	EXPECT_DOUBLE_EQ(rect4.bottomRight().x(), 1.0);
	EXPECT_DOUBLE_EQ(rect4.bottomRight().y(), 0.0);

}

TEST(Rect, InitThrow) {
	EXPECT_THROW(Rect<double> rect3({ 1.0,-1.0 }, { 0.0,0.0 }), std::invalid_argument);

	EXPECT_THROW(Rect<double> rect4({ 0.0,-1.0 }, { 1.0,0.0 }), std::invalid_argument);
}

TEST(Rect, UnionPoints) {
	Rect<double> rect1({ 0.0,0.0 }, { 0.0,0.0 });
	Rect<double> rect2({ 1.0,1.0 }, { 1.0,1.0 });

	auto rect3 = rect1.unite(rect2);
	EXPECT_DOUBLE_EQ(rect3.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect3.topLeft().y(), 1.0);
	EXPECT_DOUBLE_EQ(rect3.bottomRight().x(), 1.0);
	EXPECT_DOUBLE_EQ(rect3.bottomRight().y(), 0.0);

	Rect<double> rect4({ -1.0,-1.0 }, { -1.0,-1.0 });

	auto rect5 = rect1.unite(rect4);
	EXPECT_DOUBLE_EQ(rect5.topLeft().x(), -1.0);
	EXPECT_DOUBLE_EQ(rect5.topLeft().y(), 0.0);
	EXPECT_DOUBLE_EQ(rect5.bottomRight().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect5.bottomRight().y(), -1.0);
}

TEST(Rect, UnionSegments) {
	Rect<double> rect1({ 0.0,0.0 }, { 1.0,0.0 });
	Rect<double> rect2({ 1.0,1.0 }, { 1.0,2.0 });

	auto rect3 = rect1.unite(rect2);
	EXPECT_DOUBLE_EQ(rect3.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect3.topLeft().y(), 2.0);
	EXPECT_DOUBLE_EQ(rect3.bottomRight().x(), 1.0);
	EXPECT_DOUBLE_EQ(rect3.bottomRight().y(), 0.0);

	Rect<double> rect4({ 0.0,0.0 }, { 2.0,0.0 });

	auto rect5 = rect1.unite(rect4);
	EXPECT_DOUBLE_EQ(rect5.topLeft().x(), 0.0);
	EXPECT_DOUBLE_EQ(rect5.topLeft().y(), 0.0);
	EXPECT_DOUBLE_EQ(rect5.bottomRight().x(), 2.0);
	EXPECT_DOUBLE_EQ(rect5.bottomRight().y(), 0.0);
}



TEST(Matrix, CreateSquare)
{
	const size_t R = 128;
	const size_t C = 128;
	Matrix m(R, C);
	for (size_t r = 0; r < R; ++r)
		for (size_t c = 0; c < C; ++c)
			ASSERT_FALSE(m.get(r, c));
}

TEST(Matrix, CreateRow)
{
	const size_t C = 128;
	Matrix m(1, C);
	for (size_t c = 0; c < C; ++c)
		ASSERT_FALSE(m.get(0, c));

}

TEST(Matrix, CreateCol)
{
	const size_t R = 128;
	Matrix m(R, 1);
	for (size_t r = 0; r < R; ++r)
		ASSERT_FALSE(m.get(r, 0));
}

TEST(Matrix, SetGetSquare)
{
	const size_t R = 128;
	const size_t C = 128;
	Matrix m(R, C);
	for (size_t r = 0; r < R; ++r)
		for (size_t c = 0; c < C; ++c)
		{
			auto val = static_cast<bool>((r + c) % 2);
			m.set(r, c, val);
			ASSERT_FALSE(m.get(r, c) != val);
		}
}

TEST(Matrix, GetIncorrect)
{
	const size_t R = 128;
	const size_t C = 128;
	Matrix m(R, C);
	ASSERT_THROW(m.get(129, 1), std::out_of_range);
}

TEST(Bitmap, CreateBlackSquare) {
	const size_t width = 32;
	const size_t height = 32;
	Bitmap bmp(width, height);

	for (size_t r = 0; r < height; ++r)
		for (size_t c = 0; c < height; ++c)
			ASSERT_FALSE(bmp.Get(r, c));
}

TEST(Bitmap, CreateBlackSquareWDiagonal) {
	const size_t width = 32;
	const size_t height = 32;
	Bitmap bmp(width, height);

	for (size_t r = 0; r < height; ++r)
		bmp.Set(r, r, true);

	for (size_t r = 0; r < height; ++r)
		for (size_t c = 0; c < width; ++c)
			if (r == c)
				ASSERT_TRUE(bmp.Get(r, c));
			else
				ASSERT_FALSE(bmp.Get(r, c));
}

bool compareFiles(const std::string& p1, const std::string& p2) {
	std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
	std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);

	if (f1.fail() || f2.fail()) {
		return false; //file problem
	}

	f1.seekg(0, std::ifstream::end);
	f2.seekg(0, std::ifstream::end);

	if (f1.tellg() != f2.tellg()) {
		return false; //size mismatch
	}

	//seek back to beginning and use std::equal to compare contents
	f1.seekg(0, std::ifstream::beg);
	f2.seekg(0, std::ifstream::beg);
	return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
		std::istreambuf_iterator<char>(),
		std::istreambuf_iterator<char>(f2.rdbuf()));
}

TEST(Bitmap, SaveBlackSquare) {
	const size_t width = 32;
	const size_t height = 32;
	Bitmap bmp(width, height);
	const std::string result("resultBlack32x32.bmp");
	bmp.Save(result.c_str());

	const std::string example("exampleBlack32x32.bmp");

	ASSERT_TRUE(compareFiles(result, example));
}

TEST(Bitmap, SaveBlackSquareWDiagonal) {
	const size_t width = 32;
	const size_t height = 32;
	Bitmap bmp(width, height);
	for (size_t r = 0; r < height; ++r)
		for (size_t c = 0; c < width; ++c) {
			bmp.Set(r, c, true);
		}
	const std::string result("resultBlackWDiagonal32x32.bmp");
	bmp.Save(result.c_str());

	const std::string example("exampleBlackWDiagonal32x32.bmp");

	ASSERT_TRUE(compareFiles(result, example));
}


TEST(BitmapPrinter, SaveBlackSquare) {
	const size_t width = 32;
	const size_t height = 32;

	BitmapPrinter printer(32, 32);
	const std::string printed("printedBlack32x32.bmp");
	printer.save2File(printed.c_str());

	const std::string example("exampleBlack32x32.bmp");
	ASSERT_TRUE(compareFiles(printed, example));
}


TEST(CTransform, Square2square) {
	Rect<double> orig({ 0.0, 100.0 }, { 100.0, 0.0 });
	Rect<double> dest({ 0.0, 256.0 }, { 256.0, 0.0 });

	CTransform transform(orig, dest);

	const Point<double> origP1(100.0, 0.0);
	const Point<double> exampleP1(256.0, 0.0);
	Point<double> destP1 = transform(origP1);

	ASSERT_DOUBLE_EQ(exampleP1.x(), destP1.x());
	ASSERT_DOUBLE_EQ(exampleP1.y(), destP1.y());


	const Point<double> origP2(0.0, 0.0);
	const Point<double> exampleP2(0.0, 0.0);
	Point<double> destP2 = transform(origP2);

	ASSERT_DOUBLE_EQ(exampleP2.x(), destP2.x());
	ASSERT_DOUBLE_EQ(exampleP2.y(), destP2.y());

}


