#include <cp/cp.hpp>


/**
 * @brief Computes the cost of the pizza base, based on its type. Regular (R) -> 100, Thin crust (T) -> 120.
 * 
 * @retval 100 base_cost('R')
 * @retval 120 base_cost('T')
 */
int base_cost(char base_type) {
  if (base_type == 'R') {
    return 100;
  } else if (base_type == 'T') {
    return 120;
  }
}

/**
 * @brief Computes the additional cost of a pizza based on its size. Medium (M) -> no extra cost, Large (L) -> 30, Extra Large (X) -> 50.
 * 
 * @retval 0 size_add_cost('M')
 * @retval 30 size_add_cost('L')
 * @retval 50 size_add_cost('X')
 */
int size_add_cost(char size_type) {
  if (size_type == 'M') {
    return 0; 
  } else if (size_type == 'L') {
    return 30; 
  } else if (size_type == 'X') {
    return 50; 
  }
}

/**
 * @brief Computes the cost of toppings based on the type. Regular (R) -> 20, Cheese (C) -> 50, Veggies (V) -> 80, Meat (M) -> 120.
 * 
 * @retval 20 toppings_cost('R')
 * @retval 50 toppings_cost('C')
 * @retval 80 toppings_cost('V')
 * @retval 120 toppings_cost('M')
 */
int toppings_cost(char toppings_type) {
  if (toppings_type == 'R') {
    return 20; 
  } else if (toppings_type == 'C') {
    return 50; 
  } else if (toppings_type == 'V') {
    return 80; 
  } else if (toppings_type == 'M') {
    return 120; 
  }
}

/**
 * @brief Computes the total cost of the pizza given its base type, size, and toppings.
 * 
 * @retval 120 pizza_cost('R', 'M', 'R')
 * @retval 150 pizza_cost('R', 'M', 'C')
 * @retval 180 pizza_cost('R', 'M', 'V')
 * @retval 220 pizza_cost('R', 'M', 'M')
 */
int pizza_cost(char base_type, char size_type, char toppings_type) {
  return base_cost(base_type) + size_add_cost(size_type) + toppings_cost(toppings_type);
}

int main() {
  cp::check(100 == base_cost('R'));
  cp::check(120 == base_cost('T'));
  cp::println("All Task 1 tests pass.");
  cp::check(0 == size_add_cost('M'));
  cp::check(30 == size_add_cost('L'));
  cp::check(50 == size_add_cost('X'));
  cp::println("All Task 2 tests pass.");
  cp::check(20 == toppings_cost('R'));
  cp::check(50 == toppings_cost('C'));
  cp::check(80 == toppings_cost('V'));
  cp::check(120 == toppings_cost('M'));
  cp::println("All Task 3 tests pass.");
  cp::check(120 == pizza_cost('R', 'M', 'R'), "RMR");
  cp::check(150 == pizza_cost('R', 'M', 'C'), "RMC");
  cp::check(180 == pizza_cost('R', 'M', 'V'), "RMV");
  cp::check(220 == pizza_cost('R', 'M', 'M'), "RMM");
  cp::check(250 == pizza_cost('T', 'X', 'V'), "TXV");
  cp::check(270 == pizza_cost('T', 'L', 'M'), "TLM");
  cp::println("All Task 4 tests pass.");
  return 0;
}
