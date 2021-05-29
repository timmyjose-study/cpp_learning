#pragma once

#ifndef RATIONALS_HPP
#define RATIONALS_HPP

#include <iostream>

class Rational {
private:
  long num;
  long denom;

  void reduce();

public:
  Rational(long num, long denom) : num(num), denom(denom) { reduce(); }

  bool operator==(const Rational &);
  Rational operator+(const Rational &);
  Rational &operator+=(const Rational &);

  friend std::ostream &operator<<(std::ostream &out, const Rational &rat) {
    return out << rat.num << "/" << rat.denom;
  }
};

#endif
