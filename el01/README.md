[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7615754&assignment_repo_type=AssignmentRepo)
# Evaluative Lab 1

## Learning objectives

* Testing simple functions
* Designing simple functions
* Using simple if-else statements
* Incrementally developing your solution

## Starting point

The given starter code contains *skeletons* of two functions and test cases for one of them. Make sure you understand the given code.

## Tasks

### Task 1

Read the description (`@brief`) of the `quadrant` function and the given examples (`@retval`).

Design and implement the function `quadrant` based on this.

Run your code and make sure you get the output `"All Task 1 tests pass."`

### Task 2

Next, implement the `is_seg_in_single_quadrant` function based on its description.

Copy paste the following lines below the `cp::println("All Task 1 tests pass.");` and above the `return 0;` in `main`:

```c++
cp::check(is_seg_in_same_quadrant(1, 1, 2, 2), "1, 1, 2, 2");
cp::check(cp::not_op(is_seg_in_same_quadrant(-1, 1, 2, 2)), "-1, 1, 2, 2");
cp::check(is_seg_in_same_quadrant(-1, -1, -2, -2), "-1, -1, -2, -2");
cp::check(is_seg_in_same_quadrant(1, -1, 2, -2), "1, -1, 2, -2");
cp::println("All Task 2 tests passed.");
```

Run your program. Make sure you get the output:

```sh
All Task 1 tests pass.
All Task 2 tests pass.
```

### Task 3

Do you think you have done enough testing? Are you convinced your functions work? Add at least *two* more test cases for Task 2 and run the program again. Make sure they pass.

### Submit

Submit your work *before* the deadline by...

* clicking `Submit` in the Assignment Fetcher, or
* clicking `Push` in your Github Desktop app, or
* running `git push` on the command line.

## Evaluation

Each test case here is worth 1 point. 13 test cases (`cp::check` statements) = 13 points. 

Adding two "good" test cases = 2 points. 

Total 15.

TAs will test your solution using at least 7 other test cases (not shown), so total 22 pts.

TAs will manually check your code and award max 3 pts for overall correctness.

Total 25 pts.

Apart from these, the TAs will give you feedback on some good programming practices. Please pay attention to these comments even if they don't cost you marks in this lab. They will be important later, e.g., in exams, assignments, and other labs.
