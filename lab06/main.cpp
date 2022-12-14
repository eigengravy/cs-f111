#include <cp/cp.hpp>

/**
 * @brief Reports if the given list is empty.
 *
 * @retval true is_empty( {} )
 * @retval fast is_empty( {1.5} )
 *
 */
bool is_empty(cp::list_double list)
{
  return list.size() == 0;
}

/**
 * @brief Takes a list of numbers denoting the hours worked by each employee and the hourly rate and returns a corresponding list of wages earned but limits hours to 100 to prevent fraud.
 *
 * @retval { 0 } hours_to_wages_rate( {120} ,60)
 * @retval { 700, 1400 } hours_to_wages_rate( {10, 20}, 70 )
 * @retval {} hours_to_wages_rate( {}, 10 )
 *
 */
cp::list_double hours_to_wages_rate_limit(cp::list_double hours, double rate)
{
  cp::list_double wages;
  int i = 0;
  while (i < hours.size())
  {
    if (hours[i] > 100)
    {
      wages.insert_at(wages.size(), 0);
    }
    else
    {
      wages.insert_at(wages.size(), rate * hours[i]);
    }

    i++;
  }
  return wages;
}

/**
 * @brief Takes a list of numbers denoting the hours worked by each employee and the hourly rate and returns a corresponding list of wages earned.
 *
 * @retval { 60 } hours_to_wages_rate( {1} ,60)
 * @retval { 700, 1400 } hours_to_wages_rate( {10, 20}, 70 )
 * @retval {} hours_to_wages_rate( {}, 10 )
 *
 */
cp::list_double hours_to_wages_rate(cp::list_double hours, double rate)
{
  return hours_to_wages_rate_limit(hours,rate);
}

/**
 * @brief Takes a list of numbers denoting the hours worked by each employee and returns a corresponding list of wages earned based on the predefined hourly rate (Rs. 50).
 *
 * @retval { 50 } hours_to_wages50( {1} )
 * @retval { 500, 1000 } hours_to_wages50( {10, 20} )
 * @retval {} hours_to_wages50( {} )
 *
 */
cp::list_double hours_to_wages50(cp::list_double hours)
{
  return hours_to_wages_rate(hours, 50);
}

int main()
{
  cp::list_double real_nums = {};
  cp::check(is_empty(real_nums));
  real_nums = {1.5};
  cp::check(cp::not_op(is_empty(real_nums)));
  real_nums = {1.5,3,4};
  cp::check(cp::not_op(is_empty(real_nums)));
  cp::println("All Task 1 tests pass");

  cp::list_double hours = {4, 5, 10};
  cp::list_double answer = {4 * 50, 5 * 50, 10 * 50};
  cp::check(answer == hours_to_wages50(hours));
  hours = {7, 9, 110};
  answer = {7 * 50, 9 * 50, 0};
  cp::check(answer == hours_to_wages50(hours));
  cp::println("All Task 2 tests pass");

  hours = {4, 5, 10};
  answer = {4 * 60, 5 * 60, 10 * 60};
  cp::check(answer == hours_to_wages_rate(hours, 60));
  cp::println("All Task 3 tests pass");

  hours = {40, 50, 110};
  answer = {40 * 60, 50 * 60, 0};
  cp::check(answer == hours_to_wages_rate(hours, 60));
  cp::println("All Task 4 tests pass");

  return 0;
}