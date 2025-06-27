#include "Triangle.hpp"

int main( void ) {
	Triangle triangle = Triangle();
	bool result = triangle.bsp(Point(0, 0), Point(5, 0), Point(2.5f, 5), Point(20.5f, 2));
	return result;
}