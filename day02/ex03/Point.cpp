#include "Point.hpp"

Point::Point()
{
}
Point::Point(float const x, float const y) : x(x), y(y)
{
}
Point::Point(const Point &p) : x(p.x.toFloat()), y(p.y.toFloat())
{
}
Point &Point::operator=(const Point &p)
{
    (void) p;
    return *this;
}
Point::~Point()
{
}
const Fixed &Point::get_x() const
{
    return x;
}
const Fixed &Point::get_y() const
{
    return y;
}
bool Point::operator==(const Point &rhs) const
{
    return x == rhs.x && y == rhs.y;
}

std::ostream &operator<<(std::ostream &out, const Point &rhs)
{
    out << '(' << rhs.get_x() << ", " << rhs.get_y() << ')';
    return out;
}
