#include "complex.hpp"


Complex::Complex(const double re)
    : re(re)
{}

Complex::Complex(const double re, const double im)
    : re(re), im(im)
{}

Complex::Complex(const Complex& other)
    : re(other.re), im(other.im)
{}



Complex& Complex::operator+=(const Complex& rhs){
    this->re += rhs.re;
    this->im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs){
    this->re -= rhs.re;
    this->im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs){
    this->re = this->re * rhs.re - this->im * rhs.im;
    this->im = this->im * rhs.re + this->re * rhs.im;
    return *this;
}

Complex& Complex:: operator/=(const Complex& rhs){
	double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
	if (denominator == 0) {
		throw "ee brat, it`s division by zero";
	}
	re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	return *this;
}

Complex& Complex::operator+=(double rhs) {
	re += rhs;
	im += rhs;
	return *this;
}
Complex& Complex:: operator-=(double rhs) {
	re -= rhs;
	im -= rhs;
	return *this;
}
Complex& Complex:: operator*=(double rhs) {
	re *= rhs;
	im *= rhs;
	return *this;
}
Complex& Complex:: operator/=(double rhs) {
	if (rhs == 0) {
		throw "ee brat, it`s division by zero";
	}
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs){
    Complex new_complex = Complex(lhs);
    return new_complex += rhs;
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    Complex new_complex = Complex(lhs);
    return new_complex -= rhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    Complex new_complex = Complex(lhs);
    return new_complex *= rhs;
}


Complex operator/(const Complex& lhs, const Complex& rhs){
    Complex new_complex = Complex(lhs);
    return new_complex /= rhs;
}

Complex operator+(const Complex& lhs, const double rhs) {
	Complex new_complex = Complex(lhs);
	return new_complex += rhs;
}
Complex operator-(const Complex& lhs, const double rhs) {
	Complex new_complex = Complex(lhs);
	return new_complex -= rhs;
}
Complex operator*(const Complex& lhs, const double rhs) {
	Complex new_complex = Complex(lhs);
	return new_complex *= rhs;
}
Complex operator/(const Complex& lhs, const double rhs) {
	Complex new_complex = Complex(lhs);
	return new_complex /= rhs;
}

std::ostream& operator<<(std::ostream& out, const Complex& z) { 
    return z.writeTo(out); 
}
std::ostream& Complex::writeTo(std::ostream& out) const {
	out << '{' << re << '+' << im << '}';
	return out;
}

bool Complex:: operator==(const Complex& lhs, const Complex& rhs) {
	double epsilon = std::numeric_limits<double>::epsilon();
	return (std::fabs(lhs.re - rhs.re) < epsilon) && (std::fabs(lhs.im - rhs.im) < epsilon);
}

bool Complex:: operator!=(const Complex& lhs, const Complex& rhs) {
	double epsilon = std::numeric_limits<double>::epsilon();
	return (std::fabs(lhs.re - rhs.re) >= epsilon) || (std::fabs(lhs.im - rhs.im) >= epsilon);
}

std::istream& operator>>(std::istream& in, Complex& z) { return z.readFrom(in); }
std::istream& Complex::readFrom(std::istream& in) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	in >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (in.good()) {
		if (('{' == leftBrace) && ('+' == comma) && ('}' == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else {
			in.setstate(std::ios::failbit);
		}
	}
	return in;
}


