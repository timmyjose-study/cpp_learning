#include <iostream>
#include <memory>

class Foo {
public:
  Foo(std::string name, double size) : name(name), size(size) {}

  const std::string &get_name() const { return name; }
  double get_size() const { return size; }

private:
  std::string name;
  double size;
};

int main() {
  std::unique_ptr<Foo> foo =
      std::make_unique<Foo>(std::string("hello"), 1.23455);
  std::cout << foo->get_name() << ", " << foo->get_size() << std::endl;

  return 0;
}
