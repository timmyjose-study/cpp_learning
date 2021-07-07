#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::unique_ptr<std::string>> v;

  v.push_back(std::make_unique<std::string>("hello"));
  v.push_back(std::make_unique<std::string>("world"));
  v.push_back(std::make_unique<std::string>("we"));
  v.push_back(std::make_unique<std::string>("meet"));
  v.push_back(std::make_unique<std::string>("again"));

  std::string s = "Vector { ";
  if (!v.empty()) {
    s += *v[0];

    for (int i = 1; i < v.size(); i++) {
      s += ", ";
      s += *v[i];
    }
    s += " }";

    std::cout << s << std::endl;
  }

  return 0;
}