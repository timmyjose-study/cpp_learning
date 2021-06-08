#include <iostream>

void print() { std::cout << "base case" << std::endl; }

template <typename T, typename... Ts> void print(T t1, Ts... ts) {
  std::cout << t1 << std::endl;
  print(ts...);
}

int main() {
  print(1, 2, "Hello", "world", false, 2.23999, 'x');
  return 0;
}
