#include <cp/cp.hpp>

/**
 * @brief Returns the smaller of the given numbers.
 * 
 */
int min(int first, int second) { 
  if (first > second) {
    return second;
  } else {
    return first;
  }
}

/**
 * @brief Reports if the given non-zero divisor evenly divides the given number.
 * 
 * @retval true is_divisible(10, 5)
 * @retval true is_divisible(10, 2)
 * @retval true is_divisible(10, 1)
 * @retval true is_divisible(10, 10)
 * @retval false is_divisible(10, 7)
 * 
 */
bool is_divisible(int num, int divisor){ 
  if (num%divisor == 0) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Reports the greatest common divisor of the given positive numbers.
 * 
 * @retval 4 gcd(8, 12)
 * @retval 8 gcd(8, 16)
 * @retval 1 gcd(7, 12)
 * @retval 12 gcd(12, 12)
 */
int gcd(int first, int second) {
  int divisor = min(first,second);
  while (divisor > 0){
      if (cp::and_op(first % divisor == 0,second % divisor == 0)) {
        break;
      }
    divisor -= 1;
  }
  return divisor;
}

/**
 * @brief Reports if the given integer (greater than 1) is prime.
 * 
 * @retval true is_prime(7)
 * @retval true is_prime(17)
 * @retval false is_prime(27)
 * 
 */
bool is_prime(int candidate) {
  int divisor = 2;
  bool prime = true;
  while (divisor < candidate) {
    if (is_divisible(candidate,divisor)){
      prime = false;
      break;
    }
    divisor += 1;
  }
  return prime;
}

int main() {
  cp::check(1 == min(1, 2), "1 <- 1,2");
  cp::check(1 == min(2, 1), "1 <- 2,1");
  cp::check(true == is_divisible(10, 5), "true");
  cp::check(true == is_divisible(10, 1), "true");
  cp::check(false == is_divisible(10, 7), "false");
  cp::check(true == is_prime(7), "true");
  cp::check(false == is_prime(27), "false");
  cp::check(4 == gcd(8, 12), "4");
  cp::check(1 == gcd(7, 12), "1");
  cp::check(12 == gcd(12, 12), "12");
  cp::println("All tests pass!");

  return 0;
}