
template <typename num> struct point {
    num x;
    num y;
};
template <typename num> class Rectangle{
    public:
    Rectangle(const point& tl, const point& br);
    point<double> tl() const;
    point<double> br() const;
    private:
    point<double> topleft_;
    point<double> bottomright_;
};