#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<char> v;
  v.push_back('v');
  v.push_back('w');
  v.push_back('x');
  v.push_back('y');
  v.push_back('z');

  auto it = v.begin();

  for (int i = 0; i < 5; i++) {
    std::cout << *std::next(it, i) << std::endl;
  }

  auto it2 = v.begin();
  while (it2 != v.end()) {
    std::cout << *it2 << std::endl;
    it2++;
  }

  return 0;
}
