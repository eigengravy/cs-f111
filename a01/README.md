[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7834644&assignment_repo_type=AssignmentRepo)
# Assignment 1 - Substrings

## Learning objectives

* Using `cp::string`
* Using `while` loops
* Incrementally developing your solution

## Tasks

The main objective of this assignment is to develop a function that takes two strings and determines if the second is a substring of the first.

A string `substr_candidate` is a substring of a string `str` iff all characters of `substr_candidate` appear within `str` in the same order.

For example, `"it"` is a substring of `"bits"`. However, `"is"` is not a substring of `"bits"`. An empty string is a substring of any other string (but not of an empty string itself).

### Task 0

Think about how you will solve this problem. Don't just jump to coding!

How will you keep track of the characters that match and make a decision when then don't match?

Can you break this task down into smaller tasks - what can be your helper functions?

What code structures do you need? Conditionals? Loops? How many loops?

(You don't have to write/submit anything for this task, but it is crucial that you do this exercise before proceeding.)

### Task 1

First, develop the helper function.

Read the description (`@brief`) of the `is_substring_starting_at_pos` function and the given examples (`@retval`).

Design and implement the function to match the description.

Run your code and make sure you get the output `"All Task 1 tests pass."`

Add at least three test cases of your own and run the code again.

### Task 2

Next, implement the `is_substring` function based on its description.

Copy paste the following lines below the `cp::println("All Task 1 tests pass.");` and above the `return 0;` in `main`:

```c++
cp::check(is_substring("bits", "it"), "bits - it");
cp::check(is_substring("bits", "bi"), "bits - bi");
cp::check(is_substring("bits", "bits"), "bits - bits");
cp::check(is_substring("bits", ""), "bits - empty");
cp::check(cp::not_op(is_substring("it", "bits")), "it - bits");
cp::check(cp::not_op(is_substring("", "anystring")), "empty - anystring");
cp::check(cp::not_op(is_substring("", "")), "empty - empty");

cp::println("All Task 2 tests passed.");
```

Run your program. Make sure you get the output:

```sh
All Task 1 tests pass.
All Task 2 tests pass.
```

Add at least three test cases of your own and run the program again.

### Submit

Submit your work *before* the deadline by...

* clicking `Submit` in the Assignment Fetcher, or
* clicking `Push` in your Github Desktop app, or
* running `git push` on the command line.
