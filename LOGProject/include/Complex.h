#ifndef _COMPLEX_
#define _COMPLEX_
#include<iostream>
class complex {
private:
	double _RealVal;
	double _ImagVal;
public:
	complex(double = 0, double = 0) noexcept;
	double imag() const noexcept;
	static double imag(complex& comp) noexcept;
	double real() const noexcept;
	static double real(complex& comp) noexcept;
	friend complex operator+(const complex& c1, const complex& c2) noexcept;

	friend complex operator-(const complex& c1, const complex& c2) noexcept;

	friend complex operator*(const complex& c1, const complex& c2) noexcept;

	friend complex operator/(const complex& c1, const complex& c2);

	complex operator+=(const complex& c1) noexcept;

	complex operator-=(const complex& c1) noexcept;


	complex operator*=(const complex& c1) noexcept;


	complex operator/=(const complex& c1);

	friend std::ostream& operator<<(std::ostream& stream, const complex& c) noexcept;

};
#endif