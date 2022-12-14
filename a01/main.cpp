#include <cp/cp.hpp>

/**
 * @brief Reports whether the given `substr_candidate` is indeed a substring of `str` starting from the given `pos` within `str`.
 *
 * @retval true is_substring_starting_at_pos("bits", "it", 1)
 * @retval false is_substring_starting_at_pos("bits", "it", 0)
 * @retval true is_substring_starting_at_pos("anystring", "", 0)
 * @retval true is_substring_starting_at_pos("anystring", "", 4)
 * @retval false is_substring_starting_at_pos("", "anystring", 0)
 *
 */
bool is_substring_starting_at_pos(cp::string str, cp::string substr_candidate, int pos)
{
  int i = 0;
  bool is_substr_flag = str.length() >= substr_candidate.length();
  while (cp::and_op(is_substr_flag, i < substr_candidate.length()))
  {
    is_substr_flag = str[pos + i] == substr_candidate[i];
    i++;
  }
  return is_substr_flag;
}

/**
 * @brief Reports whether the given `substr_candidate` is indeed a substring of `str`, i.e., whether all the characters of `substr_candidate` appear in the same order somewhere within `str`.
 *
 * @retval true is_substring("bits", "it")
 * @retval true is_substring("bits", "bi")
 * @retval true is_substring("bits", "bits")
 * @retval true is_substring("bits", "")
 * @retval false is_substring("it", "bits")
 * @retval false is_substring("", "anystring")
 * @retval false is_substring("", "")
 */
bool is_substring(cp::string str, cp::string substr_candidate)
{
  int i = 0;
  while (i < str.length())
  {
    if (is_substring_starting_at_pos(str, substr_candidate, i))
    {
      return true;
    }
    i++;
  }
  return false;
}

int main()
{
  cp::check(is_substring_starting_at_pos("bits", "it", 1), "bits - it - 1");
  cp::check(cp::not_op(is_substring_starting_at_pos("bits", "it", 0)), "bits - it - 0");
  cp::check(is_substring_starting_at_pos("anystring", "", 0), "anystring - empty - 0");
  cp::check(is_substring_starting_at_pos("anystring", "", 4), "anystring - empty - 4");
  cp::check(cp::not_op(is_substring_starting_at_pos("", "anystring", 0)), "empty - anystring - 0");
  cp::check(is_substring_starting_at_pos("bits", "bits", 0), "bits - bits - 0");
  cp::check(cp::not_op(is_substring_starting_at_pos("computer", "mute", 2)), "computer - mute - 2");
  cp::check(is_substring_starting_at_pos("computer", "put", 3), "computer - put - 3");
  cp::check(is_substring_starting_at_pos("bits", "s", 3), "bits - s - 3");

  cp::println("All Task 1 tests passed.");

  cp::check(is_substring("bits", "it"), "bits - it");
  cp::check(is_substring("bits", "bi"), "bits - bi");
  cp::check(is_substring("bits", "bits"), "bits - bits");
  cp::check(is_substring("bits", ""), "bits - empty");
  cp::check(cp::not_op(is_substring("it", "bits")), "it - bits");
  cp::check(cp::not_op(is_substring("", "anystring")), "empty - anystring");
  cp::check(cp::not_op(is_substring("", "")), "empty - empty");
  cp::check(is_substring("computer", "put"), "computer - put");
  cp::check(is_substring("computer science", "computer sci"), "computer science - computer sci");
  cp::check(cp::not_op(is_substring("computer", "mute")), "computer - mute");
  cp::check(is_substring("bits", "s"), "bits - s");

  cp::println("All Task 2 tests passed.");

  return 0;
}
