template <typename num>
class Point {
    num x_, y_;
public:
    Point(num x = 0, num y = 0) : x_(x), y_(y) {}
    num px() const { return x_; }
    num py() const { return y_; }

    void set_x(num new_x) { x_ = new_x; }
    void set_y(num new_y) { y_ = new_y; }
};


template <typename num>
class Segment {
    Point<num> p1_, p2_;
public:
    Segment(Point<num> p1 = Point<num>(), Point<num> p2 = Point<num>()) : p1_(p1), p2_(p2) {}
    Point<num> p1() const { return p1_; }
    Point<num> p2() const { return p2_; }
};


template <typename num>
class Circle {
    Point<num> center_;
    double R_;
public:
    Circle(Point<num> center, double R) : center_(center), R_(R) {}
    Point<num> c() const { return center_; }
    double r() const { return R_; }
};