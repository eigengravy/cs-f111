[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7832850&assignment_repo_type=AssignmentRepo)
# Lab 06

## Learning Objectives

- Working with lists
- Designing helper functions to solve complex tasks
- Incrememntal development of your solution

## Task 1

Implement the function `is_empty` to match its description. Test it with a few more examples.

## Task 2

Implement the function `hours_to_wages50` to match its description.

Add the following test case after the Tast 1 tests and make sure it works.
Note how we are writing the `check` statements for comparing lists. We have to create lists to compare since we cannot use list literals like strings or ints.

```c++
  cp::list_double hours = {4, 5, 10};
  cp::list_double answer = {4*50, 5*50, 10*50};
  cp::check(answer == hours_to_wages50(hours));
  cp::println("All Task 2 tests pass");
```

Add at least three more test cases.

## Task 3

`hours_to_wages50` works with a fixed rate of Rs. 50 per hour. What do we have to do to incorporate a change in rate?

Design a function `hours_to_wages_rate` that takes the rate along with the list of hours worked and returns a list of wages earned based on that rate. Write the header and `@brief` description for it.

Implement this function and test it. Use the following code as a template to write more test cases.

```c++
  cp::list_double hours = {4, 5, 10};
  cp::list_double answer = {4*60, 5*60, 10*60};
  cp::check(answer == hours_to_wages_rate(hours, 60));
  cp::println("All Task 3 tests pass");
```

Now rewrite the function `hours_to_wages50` in Task 2 to use this function.

## Task 4

It is not feasible for a human to work more than 100 hours per week. To avoid frauds some employers may indulge in, design a function `hours_to_wages_rate_limit` that modifies `hours_to_wages_rate` in Task 3 such that any entry with more than 100 hours gets wage of 0, otherwise it computes the wages with the given rate, like in Task 3. Write the header and `@brief` description for this function.

Implement this function and test it. Use the following code as a template to write more test cases.

```c++
  cp::list_double hours = {40, 50, 110};
  cp::list_double answer = {40*60, 50*60, 0};
  cp::check(answer == hours_to_wages_rate(hours, 60));
  cp::println("All Task 4 tests pass");
```

Now rewrite the functions in Tasks 2 and 3 to use this function.
