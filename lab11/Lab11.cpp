#include <iostream>

/**
 * @brief Rotates the given string by `k` positions left, k > 0.
 * 
 * @retval "bca" rotate("abc", 1)
 * @retval "cab" rotate("abc", 2)
 * @retval "abc" rotate("abc", 3)
 */
std::string rotate_left(std::string str, int k) {
  return ""; // TODO
}

int main() {
  std::cout << "Enter a word or a line: ";
  std::string str;
  std::cin >> str;

  std::cout << "Enter a positive integer: ";
  int rotating_distance;
  std::cin >> rotating_distance;

  std::cout << "Rotating '" << str
    << "' left by " << rotating_distance << " gives '"
    << rotate_left(str, rotating_distance) << "'" << std::endl;

  return 0;
}
