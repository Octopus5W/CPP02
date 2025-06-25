/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:36:57 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/06/25 13:40:49 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

class Point {
	private:
	    float x;
	    float y;

	public:
	    Point();
	    Point(float x, float y);
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