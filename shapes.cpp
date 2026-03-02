#include <iostream>
#include <ctime>

enum class MutualArrange {
	POINTCOINCIDENT, // Две точки совпадают
	POINTDISTANCE // Две точки на заданном расстоянии

};

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
    srand(static_cast<unsigned int>(time(0)));

    Storage<Point<double>> pointStorage;
    Storage<Segment<double>> segmentStorage;

    double x, y;
    std::cout << "Input x and y: ";
    std::cin >> x >> y;

    Point<double> pd1(x, y);
    pointStorage.add_item(pd1);
    std::cout << "+ added point: (" << pd1.px() << ", " << pd1.py() << ")\n";

    pd1.set_x(rand() % 100);
    pd1.set_y(rand() % 100);
    pointStorage.add_item(pd1);
    std::cout << "+ added point: (" << pd1.px() << ", " << pd1.py() << ")\n";

    Point<double> pd2(3, 5);
    pointStorage.add_item(pd2);
    std::cout << "+ added point: (" << pd2.px() << ", " << pd2.py() << ")\n";

    for (size_t i = 0; i < pointStorage.get_size(); ++i) {
        Point<double>& p = pointStorage.get_item(i);
        std::cout << "point: (" << p.px() << ", " << p.py() << ")\n";
    }
    return 0;
}
