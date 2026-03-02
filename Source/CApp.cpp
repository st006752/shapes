template<typename num> struct Point {
    num x;
    num y;
};

template<typename num> struct Segment {
    Point<num> p1;
    Point<num> p2;
};

template<typename num> struct Circle {
    Point<num> center;
    double R;
};
