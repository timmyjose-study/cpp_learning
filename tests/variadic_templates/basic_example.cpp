#include <iostream>

enum Bar : unsigned short { One, Two, Three, Four, Five };

class Foo {
private:
  Bar b;

public:
  Foo(Bar b) : b(b) {}

  bool is(Bar b) const { return this->b == b; }

  bool is_one_of(Bar b1, Bar b2) const {
    return this->b == b1 || this->b == b2;
  }

  template <typename... Vs> bool is_one_of(Bar b1, Bar b2, Vs... Bs) const {
    return is(b1) || is_one_of(b2, Bs...);
  }
};

int main() {
  Foo one_foo{Bar::One};
  std::cout << one_foo.is(Bar::One) << std::endl;

  Foo two_foo{Bar::Two};
  std::cout << two_foo.is_one_of(Bar::Four, Bar::Five) << std::endl;

  Foo three_foo{Bar::Three};
  std::cout << three_foo.is_one_of(Bar::One, Bar::Three, Bar::Five)
            << std::endl;

  return 0;
}
