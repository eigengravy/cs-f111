#include <cp/cp.hpp>

/**
 * @brief Returns the non-negative fourth root of the given non-negative real number.
 * 
 * @retval 0 fourth_root(0)
 * @retval 1 fourth_root(1)
 * @retval 2 fourth_root(16)
 * 
 */
double fourth_root(double num) {
  return cp::sqrt(cp::sqrt(num)); // TODO implement function
}

int main() {
  cp::expect(0 == fourth_root(0), "fourth_root(0)");
  cp::expect(1 == fourth_root(1), "fourth_root(1)");
  cp::expect(2 == fourth_root(16), "fourth_root(16)");
  cp::println("--- Task 1 testing done! ---");

  return 0;
}