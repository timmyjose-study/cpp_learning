#include "birds.hpp"
#include <iostream>
#include <vector>

void Eagle::fly() {
  std::cout << "Eagle flying at " << speed << " in direction " << direction
            << std::endl;
}

void Vulture::fly() {
  std::cout << "Vulture flying at " << speed << " in direction " << direction
            << std::endl;
}

int main() {
  FlyingBird *eagle = new Eagle{10.01, -232.1};
  eagle->fly();

  Bird *bird_vulture = new Vulture{4.022, 1212.3239};
  Vulture *vulture = static_cast<Vulture *>(bird_vulture);
  vulture->fly();

  std::vector<FlyingBird *> birds{eagle, vulture};
  for (const auto &bird : birds) {
    bird->fly();
  }

  return 0;
}
