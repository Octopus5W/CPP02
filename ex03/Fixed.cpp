/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:19:01 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/06/27 17:51:15 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
}

Fixed::Fixed(const int value) : _fixedValue(value << _fractionalBits) {
}

Fixed::Fixed(const float value) : _fixedValue(roundf(value * (1 << _fractionalBits))) {
}

Fixed::~Fixed() {
}

Fixed::Fixed(Fixed const &copy) {
 	*this = copy;
}
	
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
  		this->_fixedValue = other._fixedValue;
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->_fixedValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedValue = raw;
}

float Fixed::toFloat(void) const {
	return ((float)(this->_fixedValue) / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const {
	return (this->_fixedValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed operator+(const Fixed &first, const Fixed &second) {
	return Fixed(first.toFloat() + second.toFloat());
}

Fixed operator-(const Fixed &first, const Fixed &second) {
	return Fixed(first.toFloat() - second.toFloat());
}

Fixed operator*(const Fixed &first, const Fixed &second) {
	return Fixed(first.toFloat() * second.toFloat());
}

Fixed operator/(const Fixed &first, const Fixed &second) {
	if (second.getRawBits() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(first.toFloat() / second.toFloat());
}

bool Fixed::operator>(const Fixed &arg) const {
	return this->_fixedValue > arg._fixedValue;
}

bool Fixed::operator<(const Fixed &arg) const {
	return this->_fixedValue < arg._fixedValue;
}

bool Fixed::operator>=(const Fixed &arg) const {
	return this->_fixedValue >= arg._fixedValue;
}

bool Fixed::operator<=(const Fixed &arg) const {
	return this->_fixedValue <= arg._fixedValue;
}

bool Fixed::operator==(const Fixed &arg) const {
	return this->_fixedValue == arg._fixedValue;
}

bool Fixed::operator!=(const Fixed &arg) const {
	return this->_fixedValue != arg._fixedValue;
}

Fixed &Fixed::operator++() {
	this->_fixedValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedValue++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_fixedValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	return (first < second ? first : second);
}

Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
	return (first < second ? const_cast<Fixed &>(first) : const_cast<Fixed &>(second));
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	return (first > second ? first : second);
}

Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
	return (first > second ? const_cast<Fixed &>(first) : const_cast<Fixed &>(second));
}