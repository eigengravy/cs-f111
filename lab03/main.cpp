#include <cp/cp.hpp>

/**
 * @brief Computes the area of a rectangle with the given positive length and width values.
 * 
 * @retval 4 area_rectangle(2, 2)
 * @retval 3 area_rectangle(1.5, 2)
 * @retval 20000 area_rectangle(100, 200)
 * 
 */
double area_rectangle(double length, double width) {
  double area = length * width;
  return area;
}

/**
 * @brief Reports if the relative error between the given double values is small enough to be considered equal. `actual` must be non-zero.
 * 
 */
bool equal_enough(double actual, double expected) {
  double relative_error = cp::abs(actual - expected) / cp::abs(actual);
  return relative_error < cp::EPSILON;
}

/**
 * @brief Computes the area of a square with the given positive side value.
 * 
 * @retval 4 area_square(2)
 * @retval 6.25 area_square(2.5)
 * 
 * @param side 
 * @return double 
 */
double area_square(double side) {
  return area_rectangle(side, side);
}


int main() {
  cp::check(4 == area_rectangle(2, 2), "expected 4");
  cp::check(3 == area_rectangle(1.5, 2), "expected 3");
  cp::check(20000 == area_rectangle(100, 200), "expected 20,000");
  cp::check(equal_enough(45.6, area_rectangle(10.0, 4.56)), "expected 45.6");

  cp::check(4 == area_square(2), "expected 4");
  cp::check(equal_enough(6.25, area_square(2.5)), "expected 6.25");
  
  cp::print("All tests passed.");

  return 0;
}