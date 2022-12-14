#include <cp/cp.hpp>


/**
 * @brief Returns the quadrant of the cartesian coordinate system the given 2D point belongs to. 
 * We define the quadrants as follows:
 *  Q1 => x > 0, y >= 0, also (0, 0)
 *  Q2 => x <= 0, y > 0
 *  Q3 => x < 0, y <= 0
 *  Q4 => x >= 0, y < 0
 * 
 * @retval 1 quadrant(1, 1)
 * @retval 2 quadrant(-1, 1)
 * @retval 3 quadrant(-1, -1)
 * @retval 4 quadrant(-1, -1)
 */
int quadrant(double x, double y) {
  int quadrant = 0;
  if (cp::or_op(cp::and_op(x > 0,y >= 0),cp::and_op(x == 0,y == 0))) {
    quadrant = 1;
  } else if (cp::and_op(x <= 0,y > 0)){
    quadrant = 2;
  }  else if (cp::and_op(x < 0,y <= 0)){
    quadrant = 3;
  }  else if (cp::and_op(x >= 0,y < 0)){
    quadrant = 4;
  } 
  return quadrant;
}

/**
 * @brief Reports if the line segment joining the given two points (P1_x, P1_y) and (P2_x, P2_y) lies entirely in a single quadrant.
 * 
 * @retval true is_seg_in_single_quadrant(1, 1, 2, 2)
 * @retval false is_seg_in_single_quadrant(-1, 1, 2, 2)
 * @retval true is_seg_in_single_quadrant(-1, -1, -2, -2)
 * @retval true is_seg_in_single_quadrant(1, -1, 2, -2)
 * 
 */
bool is_seg_in_single_quadrant(double p1_x, double p1_y, double p2_x, double p2_y) {
  if (quadrant(p1_x,p1_y) == quadrant(p2_x,p2_y)){
    return true;
  } else {
    return false;
  }
}

int main() {
  cp::check(1 == quadrant(1,1), "(1, 1)");
  cp::check(2 == quadrant(-1,1), "(-1, 1)");
  cp::check(3 == quadrant(-1,-1), "(-1, -1)");
  cp::check(4 == quadrant(1,-1), "(1, -1)");
  cp::check(1 == quadrant(0, 0), "(0, 0)");
  cp::check(1 == quadrant(1, 0), "(1, 0)");
  cp::check(2 == quadrant(0, 1), "(0, 1)");
  cp::check(3 == quadrant(-1, 0), "(-1, 0)");
  cp::check(4 == quadrant(0, -1), "(0, -1)");
  cp::println("All Task 1 tests pass.");
  cp::check(is_seg_in_single_quadrant(1, 1, 2, 2), "1, 1, 2, 2");
  cp::check(cp::not_op(is_seg_in_single_quadrant(-1, 1, 2, 2)), "-1, 1, 2, 2");
  cp::check(is_seg_in_single_quadrant(-1, -1, -2, -2), "-1, -1, -2, -2");
  cp::check(is_seg_in_single_quadrant(1, -1, 2, -2), "1, -1, 2, -2");
  cp::check(is_seg_in_single_quadrant(-1, 3, -2, 7), "-1, 3, -2, 7");
  cp::check(cp::not_op(is_seg_in_single_quadrant(5, 8, -10, 2)), "5, 8, -10, 2");
  cp::println("All Task 2 tests pass.");

  return 0;
}
