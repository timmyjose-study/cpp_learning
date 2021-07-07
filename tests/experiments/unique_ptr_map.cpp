#include <iostream>
#include <memory>
#include <unordered_map>

enum KeyType {
  Ein = 1,
  Zwei = 2,
  Drei = 3,
  Vier = 4,
  Fuenf = 5,
};

class Foo {
public:
  Foo(std::string name) : name(name) {}

  const std::string &get_name() const { return name; }
  virtual int get_id() = 0;
  virtual ~Foo() {}

private:
  std::string name;
};

class Bar : public Foo {
public:
  Bar(std::string name) : Foo(name) {}
  int get_id() override { return 100; }
};

class Baz : public Foo {
public:
  Baz(std::string name) : Foo(name) {}
  int get_id() override { return 200; }
};

static std::unordered_map<KeyType, std::unique_ptr<Foo>> m;

int main() {
  m[Ein] = std::make_unique<Bar>(std::string("hello"));
  m[Fuenf] = std::make_unique<Baz>(std::string("world"));

  std::cout << m[Ein]->get_name() << ", " << m[Ein]->get_id() << std::endl;
  std::cout << m[Ein]->get_name() << ", " << m[Ein]->get_id() << std::endl;
  std::cout << m[Fuenf]->get_name() << ", " << m[Fuenf]->get_id() << std::endl;

  return 0;
}
