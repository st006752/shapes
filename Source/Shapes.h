#pragma once
#include "Identi.h"
#include <cmath>
#include <iostream>

template <typename num> class Point {
    Identi id;
    num x_, y_;
public:
    Point(num x = 0, num y = 0) : x_(x), y_(y) {}
    
    num x() const { return x_; }
    num y() const { return y_; }
    void set_x(num x) { x_ = x; }
    void set_y(num y) { y_ = y; }
    
    Identi getId() const { return id; }
    void setId(const Identi& new_id) { id = new_id; }
};

template <typename num>
std::ostream& operator<<(std::ostream& os, const Point<num>& point) {
    os << "Point(ID: " << point.getId().getID() 
       << ", x: " << point.x() 
       << ", y: " << point.y() << ")";
    return os;
}

template <typename num> class Segment {
    Identi id;
    Point<num> p1_, p2_;
    
public:
    Segment(const Point<num>& p1 = Point<num>(), const Point<num>& p2 = Point<num>()) 
        : p1_(p1), p2_(p2) {}
    
    const Point<num>& p1() const { return p1_; }
    const Point<num>& p2() const { return p2_; }
    void set_p1(const Point<num>& p1) { p1_ = p1; }
    void set_p2(const Point<num>& p2) { p2_ = p2; }
    
    double length() const {
        double dx = p1_.x() - p2_.x();
        double dy = p1_.y() - p2_.y();
        return std::sqrt(dx*dx + dy*dy);  
    }
    
    Identi getId() const { return id; }
    void setId(const Identi& new_id) { id = new_id; }
};

template <typename num>
std::ostream& operator<<(std::ostream& os, const Segment<num>& segment) {
    os << "Segment(ID: " << segment.getId().getID() 
       << ", from (" << segment.p1().x() << ", " << segment.p1().y() 
       << ") to (" << segment.p2().x() << ", " << segment.p2().y() << "))";
    return os;
}

template<typename num> class Circle {
    Identi id;
    Point<num> center_;
    double radius_;
    
public: 
    Circle() : center_(Point<num>(0, 0)), radius_(0.0) {}
    Circle(const Point<num>& center, double radius) 
        : center_(center), radius_(radius) {}
    
    const Point<num>& center() const { return center_; }
    double radius() const { return radius_; }
    void set_center(const Point<num>& center) { center_ = center; }
    void set_radius(double radius) { radius_ = radius; }
    
    Identi getId() const { return id; }
    void setId(const Identi& new_id) { id = new_id; }
};

template<typename num>
std::ostream& operator<<(std::ostream& os, const Circle<num>& circle) {
    os << "Circle(ID: " << circle.getId().getID() 
       << ", center: (" << circle.center().x() << ", " << circle.center().y() 
       << "), radius: " << circle.radius() << ")";
    return os;
}