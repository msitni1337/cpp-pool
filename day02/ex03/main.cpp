#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0.0f, 10.0f);
    Point b(7.0f, 0.0f);
    Point c(-5.0f, 0.0f);
    Point point(0.0f, 0.0f);
    std::cout << "a = " << a << ",b = " << b << ",c = " << c << " the point " << point << "is" << (bsp(a, b, c, point) ? " inside" : " outside") << std::endl;
}