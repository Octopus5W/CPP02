#include "Triangle.hpp"

Triangle::Triangle(){}

Triangle::Triangle(const Triangle &other){}

Triangle &Triangle::operator=(const Triangle &other) {
	return *this;
}

Triangle::~Triangle() {}

float Triangle::cross_product(const Point &p1, const Point &p2, const Point &p3) const {
	return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool Triangle::bsp(Point const a, Point const b, Point const c, Point const point) {
	float cp1 = cross_product(a, b, point);
	float cp2 = cross_product(b, c, point);
	float cp3 = cross_product(c, a, point);
	bool result = (cp1 >= 0 && cp2 >= 0 && cp3 >= 0) || (cp1 <= 0 && cp2 <= 0 && cp3 <= 0);
	if (cp1 == 0 || cp2 == 0 || cp3 == 0) {
		std::cout << "Point is on the edge of the triangle." << std::endl;
	}
	else if (result) 
		std::cout << "Point is inside the triangle." << std::endl;
	else 
		std::cout << "Point is outside the triangle." << std::endl;
	return (result);
}