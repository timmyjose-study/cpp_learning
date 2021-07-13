#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
  std::string input{"1     3     Identifier foo_bar"};
  std::regex pattern("\\s+");

  std::sregex_token_iterator iter(input.begin(), input.end(), pattern, -1);
  std::sregex_token_iterator end;

  std::vector<std::string> tokens(iter, end);

  for (auto tok : tokens) {
    std::cout << tok << std::endl;
  }

  return 0;
}
