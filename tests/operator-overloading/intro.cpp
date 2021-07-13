#include <iostream>

class Cents {
private:
  int cents;

public:
  Cents(int cents) : cents(cents) {}
  int get_cents() const { return cents; }

  friend Cents operator+(const Cents &c1, const Cents &c2) {
    return Cents{c1.cents + c2.cents};
  }

  friend Cents operator-(const Cents &c1, const Cents &c2) {
    return Cents{c1.cents - c2.cents};
  }

  friend std::ostream &operator<<(std::ostream &out, const Cents cents) {
    return out << "Cents { cents: " << cents.cents << " }";
  }
};

int main() {
  Cents cents1{6};
  Cents cents2{8};
  Cents sum{cents1 + cents2};
  Cents difference{cents1 - cents2};

  std::cout << cents1 << "+" << cents2 << " = " << sum << std::endl;
  std::cout << cents1 << "+" << cents2 << " = " << difference << std::endl;

  Cents cents3{10 + sum};
  std::cout << 10 << " cents + " << sum << " = " << cents3 << std::endl;

  Cents cents4 = 10 + cents1;
  std::cout << 10 << " cents + " << cents1 << " = " << cents4 << std::endl;

  Cents cents5 = cents1 + 10;
  std::cout << cents1 << " + " << 10 << " cents = " << cents5 << std::endl;

  return 0;
}
