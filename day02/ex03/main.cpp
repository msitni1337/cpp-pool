#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0.0f, 10.0f);
    Point b(7.0f, 0.0f);
    Point c(-5.0f, 0.0f);
    Point point1(0.0f, 0.0f);
    std::cout << "a = " << a << ",b = " << b << ",c = " << c << " the point " << point1 << " is" << (bsp(a, b, c, point1) ? " inside" : " outside") << std::endl;
    Point point2(0.0f, 0.1f);
    std::cout << "a = " << a << ",b = " << b << ",c = " << c << " the point " << point2 << " is" << (bsp(a, b, c, point2) ? " inside" : " outside") << std::endl;
}