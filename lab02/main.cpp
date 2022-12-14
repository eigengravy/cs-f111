#include <cp/cp.hpp>

int main() {
  cp::print("My first program.");
  cp::print(42);
  cp::print('A');
  cp::print(true);
  cp::println(3.14);
  cp::print(cp::abs(-4.3));
  cp::print(cp::ceiling(5.32));
  cp::print(cp::sqrt(4));
  // cp::print("hello","world");
  // cp::print(12/(7-7));

  return 0;
}