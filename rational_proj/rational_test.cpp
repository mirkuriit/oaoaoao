#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include "rational.hpp"

TEST_CASE("Testing Rational class") {

    CHECK(Rational(4, 8) == Rational(1, 2));
    CHECK(Rational(-6, 9) == Rational(2, -3));
    CHECK(Rational(0, 5) == Rational(0, 1));

    CHECK(Rational(1, 2) == Rational(1, 2));
    CHECK(Rational(1, 2) != Rational(2, 3));
    CHECK(Rational(1, 2) < Rational(3, 4));
    CHECK(Rational(3, 4) > Rational(1, 2));
    CHECK(Rational(1, 2) <= Rational(1, 2));
    CHECK(Rational(3, 4) >= Rational(1, 2));

    CHECK(Rational(1, 2) + Rational(1, 2) == Rational(1, 1)); 
    CHECK(Rational(1, 2) - Rational(1, 4) == Rational(1, 4)); 
    CHECK(Rational(1, 2) * Rational(2, 3) == Rational(1, 3)); 
    CHECK(Rational(1, 2) / Rational(1, 4) == Rational(2, 1)); 


    Rational r6(1, 2);
    r6 += Rational(1, 2);
    CHECK(r6 == Rational(1, 1)); 

    Rational r7(3, 4);
    r7 -= Rational(1, 4);
    CHECK(r7 == Rational(1, 2)); 

    Rational r8(2, 3);
    r8 *= Rational(3, 4);
    CHECK(r8 == Rational(1, 2)); 

    Rational r9(1, 2);
    r9 /= Rational(1, 4);
    CHECK(r9 == Rational(2, 1)); 

    CHECK(-Rational(1, 2) == Rational(-1, 2));
    CHECK(-Rational(-3, 4) == Rational(3, 4));

    std::ostringstream oss1;
    oss1 << Rational(3, 4);
    CHECK(oss1.str() == "3/4");

    std::ostringstream oss2;
    oss2 << Rational(-3, 4);
    CHECK(oss2.str() == "-3/4");

    std::istringstream iss("5/10");
    Rational r10;
    iss >> r10;
    CHECK(r10 == Rational(1, 2)); 
}