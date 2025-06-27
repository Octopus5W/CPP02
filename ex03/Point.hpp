/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:36:57 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/06/27 17:43:40 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
	private:
	    const Fixed x;
	    const Fixed y;

	public:
	    Point();
	    Point(const Fixed x, const Fixed y);
	    Point(const Point &other);
	    Point &operator=(const Point &other);
	    ~Point();
	    float getX() const;
	    float getY() const;
	    void setX(float x);
	    void setY(float y);
	    bool operator==(const Point &other) const;
};
    
#endif