[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7876047&assignment_repo_type=AssignmentRepo)
# Evaluative Lab 02

## Learning Outcomes

- Manipulating lists
- Incremental development

## Tasks

In this lab, you will implement a function that taks a list and returns the *dominant* element in that list, i.e., the element that appears the most number of times in it. If there are more than one such elements, report the one that appears leftmost in the list.

### Task 1

Implement the function `count_occurrence` to match its description. Test it with the `expect` statements in `main`. Add at least three more test cases of your own.

### Task 2

Implement the function `dominant_element` to match its description. You can use *any* constructs introduced in the class so far. Test it with the `expect` statements in `main`. Add at least three more test cases of your own.

### Task 3 (non-evaluative)

Here is some food for thought. (You don't have to show your answer for this part to the TAs, but this is a good opportunity to think about something we will discuss later in the course.)

#### Part A

1. If your list has 10 elements, how many of them does your `count_occurrence` function access?
2. If your list has 10 elements, how many of them does your `dominant_element` function access and how many times?

#### Part B

1. If you have to develop another function `count_occurrence_double` that takes a list of `double`s and a `double` and returns the number of times the given `double` appears in the list, how different will it be from the `count_occurrence` you have developed for `int`s?
2. Similarly, if you are asked to add a function that counts occurrences of a `bool` in a list of `bools`, how different will it be from the `count_occurrence` you have developed for `int`s?

## Submit

Make sure you submit the lab before its deadline through github.

## For those who are unable to run the new docker configuration

Others can ignore!

Last week, we updated our docker environment to `0.1.2`. Our previous docker had all the functions we have used so far except these two:

1. You could not initialise a list using `{...}`
2. You could not use `cp::expect`

If you are not able to use the new docker, you can initialise the list like this and use it for testing.

```cpp
  cp::list_int nums;
  nums.insert_at(0, 1);
  nums.insert_at(1, 2);
  nums.insert_at(2, 3);
  nums.insert_at(3, 1);
```

Then, when you want to change the list to test for some other values,

```cpp
  nums.clear();
  nums.insert_at(0, 1);
  nums.insert_at(1, 2);
  nums.insert_at(2, 3);
```

And of course, you can simply use `cp::check` in place of `cp::expect` like before.

So, you can replace your `main` with the following and proceed with the lab:

```cpp
int main() {
  cp::list_int nums;
  nums.insert_at(0, 1);
  nums.insert_at(1, 2);
  nums.insert_at(2, 3);
  nums.insert_at(3, 1);
  cp::check(2 == count_occurrence(nums, 1), "count_occurrence({1, 2, 3, 1}, 1)");
  cp::check(1 == count_occurrence(nums, 2), "count_occurrence({1, 2, 3, 1}, 2)");
  cp::check(0 == count_occurrence(nums, 9), "count_occurrence({1, 2, 3, 1}, 9)");
  cp::println("All Task 1 tests pass");

  cp::check(1 == dominant_element(nums), "dominant_element({1, 2, 3, 1})");
  nums.clear();
  nums.insert_at(0, 1);
  nums.insert_at(1, 2);
  nums.insert_at(2, 1);
  nums.insert_at(3, 2);
  cp::check(1 == dominant_element(nums), "dominant_element({1, 2, 1, 2})");
  nums.clear();
  nums.insert_at(0, 1);
  nums.insert_at(1, 2);
  nums.insert_at(2, 3);
  cp::check(1 == dominant_element(nums), "dominant_element({1, 2, 3})");
  cp::println("All Task 2 tests pass");

  return 0;
}
```
