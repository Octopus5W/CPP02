/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:18:54 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/06/25 13:26:34 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed{

	private:
		int			_fixedValue;
		static const int	_fractionalBits = 8;
		
		
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &other);
		
		friend Fixed operator+(const Fixed &first, const Fixed &second);
		friend Fixed operator-(const Fixed &first, const Fixed &second);
		friend Fixed operator*(const Fixed &first, const Fixed &second);
		friend Fixed operator/(const Fixed &first, const Fixed &second);

		bool operator>(const Fixed &arg) const;
		bool operator<(const Fixed &arg) const;
		bool operator>=(const Fixed &arg) const;
		bool operator<=(const Fixed &arg) const;
		bool operator==(const Fixed &arg) const;
		bool operator!=(const Fixed &arg) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &first, Fixed &second);
		static Fixed &min(const Fixed &first, const Fixed &second);

		static Fixed &max(Fixed &first, Fixed &second);
		static Fixed &max(const Fixed &first, const Fixed &second);

		
		
		
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
		
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int	toInt(void) const;
};

#endif