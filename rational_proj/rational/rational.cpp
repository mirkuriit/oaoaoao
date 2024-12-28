#include "rational.hpp"
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <vector>

std::vector<std::int64_t> normalize(std::int64_t a, std::int64_t b) noexcept {
	std::int64_t left = std::abs(a);
	std::int64_t right = std::abs(b);
	while (right != 0) {
		std::int64_t temp = right;
		right = left % right;
		left = temp;
	}
	std::int64_t tmp_gcd = std::abs(left);
    return std::vector<std::int64_t> {a/tmp_gcd, b/tmp_gcd};
}

Rational::Rational(const std::int64_t num, const std::int64_t den) {
	if (den == 0) {
		throw std::invalid_argument("Devision by zero.");
	}
    std::vector<std::int64_t> norm_vec = normalize(num, den);
	num_ = norm_vec[0];
	den_ = norm_vec[1];
    if (den_ < 0){
        num_ *= -1;
        den_ *= -1;

    }
}

bool Rational::operator==(const Rational& rhs) const noexcept{
    return this->den()==rhs.den() and this->num()==rhs.num();
}

bool Rational::operator!=(const Rational& rhs) const noexcept{
    return !(this->den()==rhs.den() and this->num()==rhs.num());
}

bool Rational::operator>(const Rational& rhs) const noexcept{
    return (this->num())*rhs.den()>rhs.num()*(this->den());
}

bool Rational::operator>=(const Rational& rhs) const noexcept{
    return ((this->num())*rhs.den()>rhs.num()*(this->den())) or (*this)==rhs;
}

bool Rational::operator<(const Rational& rhs) const noexcept{
    return (this->num())*rhs.den()<rhs.num()*(this->den());
}

bool Rational::operator<=(const Rational& rhs) const noexcept{
    return ((this->num())*rhs.den()<rhs.num()*(this->den())) or (*this)==rhs;
}

Rational Rational::operator-() const noexcept{
    return Rational(-(*this).num(), (*this).den());
}

Rational& Rational::operator+=(const Rational& rhs) noexcept{
    std::int64_t new_num = rhs.num()*den() + num()*rhs.den();
    std::int64_t new_den = rhs.den()*den();
    std::vector<std::int64_t> norm_vec = normalize(new_num, new_den);
    num_ = norm_vec[0];
    den_ = norm_vec[1];
    return (*this);
};

Rational& Rational::operator-=(const Rational& rhs) noexcept{
    std::int64_t new_num = num()*rhs.den() - rhs.num()*den();
    std::int64_t new_den = rhs.den()*den();
    std::vector<std::int64_t> norm_vec = normalize(new_num, new_den);
    num_ = norm_vec[0];
    den_ = norm_vec[1];
    return (*this);
};

Rational& Rational::operator*=(const Rational& rhs) noexcept{
    std::int64_t new_num = num() * rhs.num();
    std::int64_t new_den = rhs.den()*den();
    std::vector<std::int64_t> norm_vec = normalize(new_num, new_den);
    num_ = norm_vec[0];
    den_ = norm_vec[1];
    return (*this);
};
Rational& Rational::operator/=(const Rational& rhs) {
    std::int64_t new_num = num() * rhs.den();
    std::int64_t new_den = rhs.num()*den();
    std::vector<std::int64_t> norm_vec = normalize(new_num, new_den);
    num_ = norm_vec[0];
    den_ = norm_vec[1];
    return (*this);
};

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << '/' << den_;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
    char slash; // Для считывания символа '/'
    std::int64_t num, den;
    
    if (istrm >> num >> slash >> den) {
        if (slash != '/') {
            istrm.setstate(std::ios_base::failbit);
            return istrm;
        }
        *this = Rational(num, den);
    } else {
        istrm.setstate(std::ios_base::failbit);
    }
    
    return istrm;
}

std::int64_t Rational::num() const noexcept{
    return num_;
}

std::int64_t Rational::den() const noexcept{
    return den_;
}

 Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
    Rational meow = Rational(lhs);
    meow += rhs;
    return meow;
 };
 Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    Rational meow = Rational(lhs);
    meow -= rhs;
    return meow;
 };
 Rational operator*(const Rational& lhs, const Rational& rhs) noexcept{
    Rational meow = Rational(lhs);
    meow *= rhs;
    return meow;
 };
 Rational operator/(const Rational& lhs, const Rational& rhs){
    Rational meow = Rational(lhs);
    meow /= rhs;
    return meow;
 };

 Rational operator+(const Rational& lhs, const int64_t rhs) noexcept{
    Rational meow = Rational(lhs);
    meow += Rational(rhs);
    return meow;
 };
 Rational operator-(const Rational& lhs, const int64_t rhs) noexcept{
    Rational meow = Rational(lhs);
    meow -= Rational(rhs);
    return meow;
 };
 Rational operator*(const Rational& lhs, const int64_t rhs) noexcept{
    Rational meow = Rational(lhs);
    meow *= Rational(rhs);
    return meow;
 };
 Rational operator/(const Rational& lhs, const int64_t rhs){
    Rational meow = Rational(lhs);
    meow /= Rational(rhs);
    return meow;
 }; 

 Rational operator+(const int64_t lhs, const Rational& rhs) noexcept{
    Rational meow = Rational(lhs);
    meow += rhs;
    return meow;
 };
 Rational operator-(const int64_t lhs, const Rational& rhs) noexcept{
    Rational meow = Rational(lhs);
    meow -= rhs;
    return meow;
 };
 Rational operator*(const int64_t lhs, const Rational& rhs) noexcept{
    Rational meow = Rational(lhs);
    meow *= rhs;
    return meow;
 };
 Rational operator/(const int64_t lhs, const Rational& rhs){
    Rational meow = Rational(lhs);
    meow /= rhs;
    return meow;
 };

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.WriteTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.ReadFrom(istrm);
}


