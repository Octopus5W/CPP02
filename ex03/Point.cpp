#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        (Fixed)this->x = (Fixed)other.x;
        (Fixed)this->y = (Fixed)other.y;
    }
    return *this;
}

Point::~Point() {}

float Point::getX() const {
    return this->x.toFloat();
}

float Point::getY() const {
    return this->y.toFloat();
}
