#include <iostream>
#include <ctime>


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


template <typename Item>
class Storage {
private:
    Item* array;
    size_t size;
    size_t capacity;

public:
    Storage(size_t start_capacity = 10) : size(0), capacity(start_capacity) {
        array = new Item[capacity];
    }
    void initialize(size_t start_capacity) {
        capacity = start_capacity;
        array = new Item[capacity];
        size = 0;
    }
    ~Storage() {
        delete[] array;
    }


    void add_item(const Item& item) {
        if (size == capacity) {

            capacity *= 2;
            Item* new_array = new Item[capacity];
            for (size_t i = 0; i < size; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        array[size] = item;
        ++size;
    }


    Item& get_item(size_t index) const {
        return array[index];
    }


    size_t get_size() const {
        return size;
    }
};

int main() {
    
     App app;
     Identi i1 = app.addObject(POINT);
     Identi i2 = app.addObject(POINT);

     app.addArange(POINTCOINCIDENT,i1, i2);

     Identi i3 = app.addObject(SEGMENT);
     Identi i4 = app.addObject(SEGMENT);

     app.addArange(SEGMENTSNORMAL,i3,i4);

     Identi i5 = app.addObject(POINT);

     app.addArange(POINTOBELONGSEGMENT,i5,i3);
     app.addArange(POINTOBELONGSEGMENT,i3,i5);

     app.addArange(SEGMENTLENGTH,i3 , 10.1 );


    return 0;
}
