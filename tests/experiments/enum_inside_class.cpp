#include <iostream>

class Foo {
public:
  enum Bar : unsigned short {
    Baz = 0,
    Quux,
    Foobar,

  };
};

// clang bug forces this to be defined
static inline std::ostream &operator<<(std::ostream &out, const Foo::Bar &bar) {
  return out << static_cast<std::underlying_type<Foo::Bar>::type>(bar);
}

int main() {
  std::cout << Foo::Bar::Baz << std::endl;
  std::cout << Foo::Quux << std::endl;

  return 0;
}