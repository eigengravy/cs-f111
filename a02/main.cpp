#include <cp/cp.hpp>

/**
 * @brief Represents a set of integers. No duplicate values. No specific order.
 *
 */
struct set_int
{
  cp::list_int value;
};

/**
 * @brief Reports the number of elements in the set.
 *
 * @retval 0 set_size({})
 * @retval 2 set_size({1, 2})
 *
 */
int set_size(set_int *s)
{
  return s->value.size();
}

/**
 * @brief Reports if the given integer is a member of the given set.
 *
 * @retval false set_contains({}, 1)
 * @retval false set_contains({2}, 1)
 * @retval true set_contains({1, 2}, 1)
 * @retval true set_contains({1, 2}, 2)
 *
 */
bool set_contains(set_int *s, int x)
{
  bool found = false;
  int i = 0;
  while (cp::and_op(i < set_size(s), cp::not_op(found)))
  {
    if (s->value[i] == x)
    {
      found = true;
    }
    i++;
  }
  return found;
}

/**
 * @brief Inserts the given element into the set.
 *
 * @retval set_insert({}, 1) -> {1}
 * @retval set_insert({1, 2}, 1) -> {1, 2}
 * @retval set_insert({2, 3}, 1) -> {1, 2, 3}
 *
 */
void set_insert(set_int *s, int x)
{
  if (cp::not_op(set_contains(s, x)))
  {
    s->value.insert_at(set_size(s), x);
  }
}

/**
 * @brief Removes the given element from the set. The given element must be a member of the set.
 *
 * @retval set_remove({1}, 1) -> {}
 * @retval set_insert({1, 2}, 1) -> {2}
 *
 */
void set_remove(set_int *s, int x)
{
  int index;
  bool found = false;
  int i = 0;
  while (cp::and_op(i < set_size(s), cp::not_op(found)))
  {
    if (s->value[i] == x)
    {
      found = true;
      index = i;
    }
    i++;
  }
  if (found)
    s->value.remove_from(index);
}

/**
 * @brief Replaces the old value of `result` with the elements that are in common with both `first` and `second`.
 *
 * @retval set_intersection({1, 2}, {1, 3}, {}) -> {1}
 * @retval set_intersection({1, 2}, {3, 4}, {}) -> {}
 *
 */
void set_intersection(set_int *first, set_int *second, set_int *result)
{
  result->value = {};
  for (int i = 0; i < set_size(first); i++)
  {
    if (set_contains(second, first->value[i]))
    {
      set_insert(result, first->value[i]);
    }
  }
}

/**
 * @brief Copies the elements that are in  `first` into `second`.
 *
 * @retval set_copy({1, 2},  {}) -> {1, 2}
 * @retval set_copy({1, 3}, {5, 6}) -> {1, 3, 5, 6}
 *
 */
void set_copy(set_int *first, set_int *second) 
{
  for( int i = 0; i < set_size(first); i++) 
  {
    set_insert(second, first->value[i]);
  }
}

/**
 * @brief Replaces the old value of `result` with the elements that are in  `first` or `second`.
 *
 * @retval set_union({1, 2}, {2, 3}, {}) -> {1, 2, 3}
 * @retval set_union({1, 3}, {5, 7}, {5, 6}) -> {1, 3, 5, 7}
 *
 */
void set_union(set_int *first, set_int *second, set_int *result)
{
  result->value = {};
  set_copy(first, result);
  set_copy(second, result);
}

/**
 * @brief Reports if the two given sets have the same elements irrespective of the order.
 *
 * @retval true set_equal({1, 2}, {2, 1})
 * @retval false set_equal({}, {2, 1})
 *
 */
bool set_equal(set_int *first, set_int *second)
{
  bool equal = true;
  int i = 0;
  while (i < set_size(first))
  {
    if (cp::not_op(set_contains(second, first->value[i])))
    {
      equal = false;
    }
    i++;
  }
  return cp::and_op(equal, set_size(first) == set_size(second));
}

/**
 * @brief A string representation of the set.
 *
 * @retval [] to_string({})
 * @retval [1, 2] to_string({1, 2})
 *
 */
cp::string to_string(set_int *s)
{
  return s->value.to_string();
}

int main()
{
  set_int first = {{1, 2}};
  set_int second = {{2, 4}};
  set_int third = {{3,4,5}};
  set_int fourth = {{7,8,9,10}};
  set_int result;
  set_int exp;

  cp::println(to_string(&first));
  cp::println(to_string(&second));
  cp::println("--- Task 1 done ---");

  cp::expect(2 == set_size(&first), "first size");
  cp::expect(2 == set_size(&second), "second size");
  cp::expect(3 == set_size(&third), "third size");
  cp::expect(4 == set_size(&fourth), "fourth size");
  cp::println("--- Task 2 done ---");

  cp::expect(set_contains(&first, 1), "first contains 1");
  cp::expect(cp::not_op(set_contains(&first, 4)), "first does not contain 4");
  cp::expect(set_contains(&third, 3), "third contains 3");
  cp::expect(cp::not_op(set_contains(&fourth, 4)), "fourth does not contain 4");
  cp::println("--- Task 3 done ---");

  set_insert(&second, 6);
  exp = {{2, 4, 6}};
  cp::expect(set_equal(&exp, &second), "6 inserted in second");
  set_insert(&third, 6);
  exp = {{6,3,4,5}};
  cp::expect(set_equal(&exp, &third), "6 inserted in third");
  set_insert(&fourth, 4);
  exp = {{7,8,9,4,10}};
  cp::expect(set_equal(&exp, &fourth), "4 inserted in fourth");
  cp::println("--- Task 4 done ---");

  set_remove(&second, 4);
  exp = {{2, 6}};
  cp::expect(set_equal(&exp, &second), "4 removed from second");
  set_remove(&third, 3);
  exp = {{6,4,5}};
  cp::expect(set_equal(&exp, &third), "3 removed from third");
  set_remove(&fourth, 10);
  exp = {{4,7,8,9}};
  cp::expect(set_equal(&exp, &fourth), "10 removed from fourth");
  cp::println("--- Task 5 done ---");

  set_intersection(&first, &second, &result);
  exp = {{2}};
  cp::expect(set_equal(&exp, &result), "first ^ second");
  set_intersection(&third, &fourth, &result);
  exp = {{4}};
  cp::expect(set_equal(&exp, &result), "third ^ fourth");
  set_intersection(&first, &fourth, &result);
  exp = {{}};
  cp::expect(set_equal(&exp, &result), "first ^ fourth");
  cp::println("--- Task 6 done ---");

  set_union(&first, &second, &result);
  exp = {{1, 2, 6}};
  cp::expect(set_equal(&exp, &result), "first U second");
  set_union(&third, &fourth, &result);
  exp = {{4,5,6,7,8,9}};
  cp::expect(set_equal(&exp, &result), "third U fourth");
  set_union(&second, &third, &result);
  exp = {{2,6,4,5}};
  cp::expect(set_equal(&exp, &result), "second U third");
  cp::println("--- Task 7 done ---");

  return 0;
}