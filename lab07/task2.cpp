#include <cp/cp.hpp>

/**
 * @brief Reports the largest of the given non-empty list of numbers.
 * 
 * @retval 7 largest({1, 3, 5, 7})
 * @retval 0 largest({-1, 0, -10, -3})
 * 
 */
int largest(cp::list_int nums) {
  int i = 0;
  int current_largest = nums[0];
  int len = nums.size();
  while (i < len) {
    if (nums[i] > current_largest) {
      current_largest = nums[i];
    }
    i++;
  }
  return current_largest; 
}

/**
 * @brief Prints the given list in reverse order enclosed in square brackets with elements separated by commas.
 * 
 * @retval [] to_string_reverse({})
 * @retval [2, 1] to_string_reverse({1, 2})
 * @retval [-8, 3, -5] to_string_reverse({-5, 3, -8})
 */
cp::string to_string_reverse(cp::list_int nums) {
  cp::string answer;
  cp::list_int new_nums;
  int i = nums.size() - 1;
  while (i >= 0) {
    new_nums.insert_at(nums.size() - i - 1, nums[i]);
    i--;
  }
  answer = new_nums.to_string();
  return answer;
}

int main() {
  cp::list_int nums = {1, 3, 5, 7};
  cp::expect(7 == largest(nums), "largest({1, 3, 5, 7})");
  nums = {-1, 0, -10, -3};
  cp::expect(0 == largest(nums), "largest({-1, 0, -10, -3})");
  nums = {32, -40, 2, 0};
  cp::expect(32 == largest(nums), "largest({32, -40, 2, 0})");
  nums = {0, 0, 0};
  cp::expect(0 == largest(nums), "largest({0, 0, 0})");
  nums = {5};
  cp::expect(5 == largest(nums), "largest({5})");
  cp::println("--- Task 2a testing done! ---");

  nums = {};
  cp::expect("[]" == to_string_reverse(nums), "to_string_reverse({})");
  nums = {1, 2};
  cp::expect("[2, 1]" == to_string_reverse(nums), "to_string_reverse({1, 2})");
  nums = {-5, 3, -8};
  cp::expect("[-8, 3, -5]" == to_string_reverse(nums), "to_string_reverse({-5, 3, -8})");
  nums = {7, 32, -5};
  cp::expect("[-5, 32, 7]" == to_string_reverse(nums), "to_string_reverse({7, 32, -5})");
  nums = {0};
  cp::expect("[0]" == to_string_reverse(nums), "to_string_reverse({0})");
  nums = {2, 1, 1, 2};
  cp::expect("[2, 1, 1, 2]" == to_string_reverse(nums), "to_string_reverse({2, 1, 1, 2})");
  cp::println("--- Task 2b testing done! ---");

  return 0;
}