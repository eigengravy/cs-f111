#include <cp/cp.hpp>

/**
 * @brief Reports whether the given list is in non-decreasing order.
 * 
 * @retval true is_non_decreasing([])
 * @retval true is_non_decreasing([1])
 * @retval true is_non_decreasing([1, 2])
 * @retval false is_non_decreasing([2, 1])
 * 
 */
bool is_non_decreasing(cp::list_int a_list) {
  if(a_list.size() <= 1){
    return true;
  }
  int head = a_list.remove_from(0);
  return cp::and_op(head <= a_list[0], is_non_decreasing(a_list));
}

/**
 * @brief Reports if the given list is a palindrome, i.e., whether it reads the same left to right and right to left.
 * 
 * @retval true is_palindrome([])
 * @retval true is_palindrome([1])
 * @retval false is_palindrome([1, 2])
 * @retval true is_palindrome([1, 1])
 * 
 */
bool is_palindrome(cp::list_int a_list) {
  if(a_list.size() <= 1){
    return true;
  }
  int head = a_list.remove_from(0);
  int tail = a_list.remove_from(a_list.size()-1);
  return cp::and_op(head==tail,is_palindrome(a_list));
}

int main() {
  cp::list_int nums = { };
  cp::expect(is_palindrome(nums), "[] is palindrome");

  nums = { 1 };
  cp::expect(is_palindrome(nums), "[1] is palindrome");

  nums = { 1, 2 };
  cp::expect(cp::not_op(is_palindrome(nums)), "[1, 2] is not a palindrome");

  nums = { 1, 1 };
  cp::expect(is_palindrome(nums), "[1, 1] is a palindrome");
  
  nums = {1,2,1};
  cp::expect(is_palindrome(nums), "[1, 2, 1] is a palindrome");

  nums = {1,2,3,4,2,1};
  cp::expect(cp::not_op(is_palindrome(nums)), "[1, 2, 3, 4, 2, 1] is not a palindrome");

  nums = {};
  cp::expect(is_non_decreasing(nums), "[] is nondecreasing");
  nums = {1};
  cp::expect(is_non_decreasing(nums), "[1] is nondecreasing");
  nums = {1, 2};
  cp::expect(is_non_decreasing(nums), "[1, 2] is nondecreasing");
  nums = {2,1};
  cp::expect(cp::not_op(is_non_decreasing(nums)), "[2, 1] is not nondecreasing");
  nums = {1, 2, 2, 3};
  cp::expect(is_non_decreasing(nums), "[1, 2, 2, 3] is nondecreasing");
  nums = {1, 2, 2, 1, 3};
  cp::expect(cp::not_op(is_non_decreasing(nums)), "[1, 2, 2, 1, 3] is not nondecreasing");
  
  return 0;
}
