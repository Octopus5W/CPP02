#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Point.hpp"

class Triangle {
	private:
		Point a;
		Point b;
		Point c;
	public:
		Triangle();
		Triangle(const Triangle &other);
		Triangle &operator=(const Triangle &other);
		~Triangle();
		
		float cross_product(const Point &p1, const Point &p2, const Point &p3) const;
		bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif