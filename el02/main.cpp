#include <cp/cp.hpp>

/**
 * @brief Reports the number of times the given number appears in the given list.
 * 
 * @retval 2 count_occurrence({1, 2, 3, 1}, 1)
 * @retval 1 count_occurrence({1, 2, 3, 1}, 2)
 * @retval 0 count_occurrence({1, 2, 3, 1}, 9)
 * @retval 0 count_occurrence({}, 1)
 */
int count_occurrence(cp::list_int a_list, int a_num) {
  int count = 0;
  int i = 0;
  int size = a_list.size();
  while(i < size) {
    if(a_list[i] == a_num) count++;
    i++;
  }
  return count; 
}

/**
 * @brief Reports the leftmost integer with the highest number of occurrneces in the given non-empty list. If there are more than one such integers, reports the one that appears leftmost among them.
 * 
 * @retval 1 dominant_element({1, 2, 3, 1})
 * @retval 1 dominant_element({1, 2, 1, 2})
 * @retval 1 dominant_element({1, 2, 3})
 * 
 */
int dominant_element(cp::list_int a_list) {
  int highest_occurance = 0;
  int highest_occurance_index = 0;
  int i = 0;
  int size = a_list.size();
  while (i < size) {
    int occurance = count_occurrence(a_list, a_list[i]);
    if (occurance > highest_occurance) {
      highest_occurance = occurance;
      highest_occurance_index = i;
    }
    i++;
  }
  return a_list[highest_occurance_index]; 
}

int main() {
  cp::list_int nums = {1, 2, 3, 1};
  cp::expect(2 == count_occurrence(nums, 1), "count_occurrence({1, 2, 3, 1}, 1)");
  cp::expect(1 == count_occurrence(nums, 2), "count_occurrence({1, 2, 3, 1}, 2)");
  cp::expect(0 == count_occurrence(nums, 9), "count_occurrence({1, 2, 3, 1}, 9)");
  nums = {};
  cp::expect(0 == count_occurrence(nums, 1), "count_occurrence({}, 1)");
  nums = {1, -1, 2, 0, 2, 2, 0, 0};
  cp::expect(1 == count_occurrence(nums, -1), "count_occurrence({1, -1, 2, 0, 2, 2, 0, 0}, -1)");
  cp::expect(3 == count_occurrence(nums, 0), "count_occurrence({1, -1, 2, 0, 2, 2, 0, 0}, 0)");
  cp::expect(0 == count_occurrence(nums, 10), "count_occurrence({1, -1, 2, 0, 2, 2, 0, 0}, 10)");
  cp::println("--- Task 1 testing done ---");

  nums = {1, 2, 3, 1};
  cp::expect(1 == dominant_element(nums), "dominant_element({1, 2, 3, 1})");
  nums = {1, 2, 1, 2};
  cp::expect(1 == dominant_element(nums), "dominant_element({1, 2, 1, 2})");
  nums = {1, 2, 3};
  cp::expect(1 == dominant_element(nums), "dominant_element({1, 2, 3})");
  nums = {1, 2, 1, 2, 2};
  cp::expect(2 == dominant_element(nums), "dominant_element({1, 2, 1, 2, 2})");
  nums = {3};
  cp::expect(3 == dominant_element(nums), "dominant_element({3})");
  nums = {3, 3, 1, 1, 1, 3};
  cp::expect(3 == dominant_element(nums), "dominant_element({3, 3, 1, 1, 1, 3})");
  cp::println("--- Task 2 testing done ---");

  return 0;
}