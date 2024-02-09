#include "../include/Complex.h"
#include<iostream>
complex::complex(double a, double b) noexcept : _RealVal{ a }, _ImagVal{ b } {

}
double complex::imag() const noexcept {
	return _ImagVal;
}
double complex::imag(complex& comp) noexcept {
	return comp.imag();
}
double complex::real() const noexcept {
	return _RealVal;
}
double complex::real(complex& comp) noexcept {
	return comp.real();
}
complex operator+(const complex& c1, const complex& c2) noexcept {
	return complex{ c1._RealVal + c2._RealVal, c1._ImagVal + c2._ImagVal };
}

complex operator-(const complex& c1, const complex& c2) noexcept {
	return complex{ c1._RealVal - c2._RealVal, c1._ImagVal - c2._ImagVal };
}


complex operator*(const complex& c1, const complex& c2) noexcept {
	return complex{ c1._RealVal * c2._RealVal - c1._ImagVal * c2._ImagVal, c1._RealVal * c2._ImagVal + c1._ImagVal * c2._RealVal };
}


complex operator/(const complex& c1, const complex& c2) {
	double denominator = c1._RealVal * c1._RealVal + c2._ImagVal * c2._ImagVal;
	if (denominator == 0) throw "Invalid division";
	complex temp{ c1 * complex{c2._RealVal, -c2._ImagVal} };
	return complex{ temp._ImagVal / denominator, temp._RealVal / denominator };
}

complex complex::operator+=(const complex& c1) noexcept {
	return (*this) + c1;
}

complex complex::operator-=(const complex& c1) noexcept {
	return (*this) - c1;
}


complex complex::operator*=(const complex& c1) noexcept {
	return (*this) * c1;
}


complex complex::operator/=(const complex& c1) {
	return (*this) / c1;
}


std::ostream& operator<<(std::ostream& stream, const complex& c) noexcept {
	stream << c._RealVal << " + " << c._ImagVal << " i\n";
	return stream;
}