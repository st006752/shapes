#pragma once
class Identi{
	bool operator==(Identi i2);
};

bool operator==(Identi i1, Identi i2){

	return false;
}


template<typename num> struct Point {
    Identi id;
    num x;
    num y;
};

template<typename num> struct Segment {
    Identi id;
    Point<num> p1;
    Point<num> p2;
};

template<typename num> struct Circle {
    Identi id;
    Point<num> center;
    double R;
};
