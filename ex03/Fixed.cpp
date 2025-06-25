/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:19:01 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/06/25 13:32:35 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedValue(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedValue(roundf(value * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	 std::cout << "Copy constructor called" << std::endl;
 	*this = copy;
}
	
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
  		this->_fixedValue = other._fixedValue;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
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