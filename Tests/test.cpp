#include <iostream>
#include <gtest/gtest.h>
#include "../Source/Matrix.h"


#include "../Source/App.h"
#include "../Source/Relations.h"
#include <cmath>

// TEST (Matrix, CreateSquare)
// {
// 	const size_t R = 128;
// 	const size_t C = 128;
// 	Matrix m(R, C);
// 	for (size_t r = 0; r < R; ++r)
// 		for (size_t c = 0; c < C; ++c)
// 			ASSERT_FALSE (m.get(r, c));
// }

// TEST (Matrix, CreateRow)
// {
// 	const size_t C = 128;
// 	Matrix m(1, C);
// 	for (size_t c = 0; c < C; ++c)
// 		ASSERT_FALSE (m.get(0, c));

// }

// TEST (Matrix, CreateCol)
// {
// 	const size_t R = 128;
// 	Matrix m(R, 1);
// 	for (size_t r = 0; r < R; ++r)
// 		ASSERT_FALSE (m.get(r, 0));
// }

// TEST (Matrix, SetGetSquare)
// {
// 	const size_t R = 128;
// 	const size_t C = 128;
// 	Matrix m(R, C);
// 	for (size_t r = 0; r < R; ++r)
// 		for (size_t c = 0; c < C; ++c)
// 		{
// 			auto val = static_cast<bool>((r + c) % 2);
// 			m.set(r, c, val);
// 			ASSERT_FALSE (m.get(r, c) != val);
// 		}
// }

// TEST (Matrix, GetIncorrect)
// {
// 	const size_t R = 128;
// 	const size_t C = 128;
// 	Matrix m(R, C);
// 	ASSERT_THROW (m.get(129, 1), std::out_of_range);
// }


TEST(PointDistance, SamePoint) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    
    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point = app.findObjectById(p1, points);
    point->set_x(0);
    point->set_y(0);
    
    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p1);
    
    PointDistanceRelation relation(Identi(), ids);
    EXPECT_DOUBLE_EQ(relation.measure(app), 0.0);
}

TEST(PointDistance, DifferentPoints) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    Identi p2 = app.addObject(PrimitiveType::POINT);

    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point1 = app.findObjectById(p1, points);
    Point<double>* point2 = app.findObjectById(p2, points);
    point1->set_x(-1);
    point1->set_y(-1);
    point2->set_x(2);
    point2->set_y(3);

    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p2);

    PointDistanceRelation relation(Identi(), ids);
    EXPECT_DOUBLE_EQ(relation.measure(app), 5.0);
}

TEST(PointCoincident, SamePoint) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    
    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point = app.findObjectById(p1, points);
    point->set_x(0);
    point->set_y(0);
    
    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p1);
    
    PointCoincidentRelation relation(Identi(), ids);
    EXPECT_DOUBLE_EQ(relation.measure(app), 0.0);
}

TEST(PointCoincident, DifferentPoints) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    Identi p2 = app.addObject(PrimitiveType::POINT);
    
    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point1 = app.findObjectById(p1, points);
    Point<double>* point2 = app.findObjectById(p2, points);
    
    point1->set_x(1);
    point1->set_y(2);
    point2->set_x(4);
    point2->set_y(6);
    
    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p2);
    
    PointCoincidentRelation relation(Identi(), ids);
    double distance = relation.measure(app);
    EXPECT_DOUBLE_EQ(distance, 5.0);
}

TEST(SegmentVertical, VerticalSegment) {
    App app;
    Identi s1 = app.addObject(PrimitiveType::SEGMENT);

    Storage<Segment<double>>& segments = const_cast<Storage<Segment<double>>&>(app.getSegments());
    Segment<double>* segment = app.findObjectById(s1, segments);
    segment->set_p1(Point<double>(2, 0));
    segment->set_p2(Point<double>(2, 5));

    Storage<Identi> ids;
    ids.addItem(s1);

    SegmentVerticalRelation relation(Identi(), ids);
    EXPECT_DOUBLE_EQ(relation.measure(app), 0.0);
}

TEST(SegmentVertical, NonVerticalSegment) {
    App app;
    Identi s1 = app.addObject(PrimitiveType::SEGMENT);

    Storage<Segment<double>>& segments = const_cast<Storage<Segment<double>>&>(app.getSegments());
    Segment<double>* segment = app.findObjectById(s1, segments);
    segment->set_p1(Point<double>(0, 0));
    segment->set_p2(Point<double>(4, 0));

    Storage<Identi> ids;
    ids.addItem(s1);

    SegmentVerticalRelation relation(Identi(), ids);
    EXPECT_DOUBLE_EQ(relation.measure(app), 4.0);
}

TEST(SegmentVertical, NegativeDirection) {
    App app;
    Identi s1 = app.addObject(PrimitiveType::SEGMENT);

    Storage<Segment<double>>& segments = const_cast<Storage<Segment<double>>&>(app.getSegments());
    Segment<double>* segment = app.findObjectById(s1, segments);
    segment->set_p1(Point<double>(3, 1));
    segment->set_p2(Point<double>(-2, 7));

    Storage<Identi> ids;
    ids.addItem(s1);

    SegmentVerticalRelation relation(Identi(), ids);
    EXPECT_DOUBLE_EQ(relation.measure(app), 5.0);
}