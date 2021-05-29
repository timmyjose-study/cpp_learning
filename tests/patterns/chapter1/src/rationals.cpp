#include "rationals.hpp"
#include <cassert>

long gcd(long x, long y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}

void Rational::reduce() {
  long g = gcd(num, denom);
  num /= g;
  denom /= g;
}

bool Rational::operator==(const Rational &other) {
  return num == other.num && denom == other.denom;
}

Rational Rational::operator+(const Rational &other) {
  long numerator = num * other.denom + denom * other.num;
  long denonimator = denom * other.denom;

  return Rational{numerator, denonimator};
}

Rational &Rational::operator+=(const Rational &other) {
  num = num * other.denom + denom * other.num;
  denom *= other.denom;
  reduce();

  return *this;
}

int main() {
  Rational r1{2, 3};
  Rational r2{3, 4};

  Rational r3 = r1 + r1;
  assert(r3 == (Rational{4, 3}));

  r1 += r2;
  assert(r1 == (Rational{17, 12}));

  return 0;
}
