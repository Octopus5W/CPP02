#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
    this->x = other.x;
    this->y = other.y;
    }
    return *this;
}

Point::~Point() {}

float Point::getX() const {
    return this->x;
}

float Point::getY() const {
    return this->y;
}

void Point::setX(float x) {
    this->x = x;
}

void Point::setY(float y) {
    this->y = y;
}