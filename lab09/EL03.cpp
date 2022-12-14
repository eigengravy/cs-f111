#include <cp/cp.hpp>

/**
 * @brief Reports the average (rounded down the nearest integer) of the given non-empty list of integers.
 * 
 * @retval 2 average({1, 3, 4})
 * 
 */
int average(cp::list_int marks) {
  int len = marks.size();
  int sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum += marks[i];
  }
  
  int average = sum / len;
  return average;
}

/**
 * @brief Returns the smallest value in the given non-empty list of integers.
 * 
 * @retval 1 min({1, 3, 4})
 * 
 */
int min(cp::list_int marks) {
  int lowest = marks[0];
  for (int i = 0; i< marks.size();i++) {
    if(marks[i]<lowest){
      lowest = marks[i];
    }
  }
  return lowest;
}

/**
 * @brief Returns the largest value in the given non-empty list of integers.
 * 
 * @retval 4 max({1, 3, 4})
 * 
 */
int max(cp::list_int marks) {
  int highest = marks[0];
  for (int i = 0; i< marks.size();i++) {
    if(marks[i]>highest){
      highest = marks[i];
    }
  }
  return highest;
}

/**
 * @brief Reports the number of elements in the list that are below the average value of the given non-empty list.
 * 
 * @retval 1 count_below_average({1, 3, 4})
 * 
 */
int count_below_average(cp::list_int marks) {
  int avg = average(marks);
  int count = 0;
  for (int i = 0; i < marks.size(); i++)
  {
    if (marks[i]<avg) {
      count++;
    }
  }
  return count;
}

/**
 * @brief Reports the number of elements in the list that are equal to or above the average value of the given non-empty list.
 * 
 * @retval 2 count_above_average({1, 3, 4})
 * 
 */
int count_above_average(cp::list_int marks) {
  int avg = average(marks);
  int count = 0;
  for (int i = 0; i < marks.size(); i++)
  {
    if (marks[i]>=avg) {
      count++;
    }
  }
  return count;
}

int main() {
  cp::list_int marks = { 20, 50, 60, 70, 30 };
  cp::list_int marks2 = { 33,44,55,37,86,76 };
  cp::list_int marks3 = { 12,67,98,45,56,37,87,34,56 };

  cp::expect(46 == average(marks), "avg is 46");
  cp::expect(55 == average(marks2), "avg is 55");
  cp::expect(54 == average(marks3), "avg is 54");

  cp::expect(20 == min(marks), "min is 20");
  cp::expect(33 == min(marks2), "min is 33");
  cp::expect(12 == min(marks3), "min is 12");

  cp::expect(70 == max(marks), "max is 70");
  cp::expect(86 == max(marks2), "max is 86");
  cp::expect(98 == max(marks3), "max is 98");

  cp::expect(2 == count_below_average(marks), "2 people are below avg");
  cp::expect(3 == count_below_average(marks2), "3 people are below avg");
  cp::expect(4 == count_below_average(marks3), "4 people are below avg");

  cp::expect(3 == count_above_average(marks), "3 people are above avg");
  cp::expect(3 == count_above_average(marks2), "3 people are above avg");
  cp::expect(5 == count_above_average(marks3), "5 people are above avg");

  return 0;
}