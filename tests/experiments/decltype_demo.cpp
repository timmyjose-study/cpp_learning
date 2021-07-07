#include <iostream>

int fun() { return 42; }

int main() {
  decltype(fun()) x;
  x = 21;
  std::cout << x << std::endl;

  decltype(x) j = x + 21;
  std::cout << typeid(j).name() << " " << j << std::endl;

  return 0;
}
