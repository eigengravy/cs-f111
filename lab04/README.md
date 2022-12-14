[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7615409&assignment_repo_type=AssignmentRepo)
# Evaluative Lab 1

## Learning objectives

* Testing simple functions
* Designing simple functions
* Using simple if-else statements
* Incrementally developing your solution

## Starting point

The given starter code contains *skeletons* of four functions and test cases for one of them. Make sure you understand the given code.

## Tasks

### Task 1

Read the description (`@brief`) of the `base_cost` function and the given examples (`@retval`).

Design and implement the function `base_cost` based on this.

Run your code and make sure you get the output `"All Task 1 tests pass."`

### Task 2

Next, implement the `size_add_cost` function based on its description.

Copy paste the following lines below the `cp::println("All Task 1 tests pass.");` and above the `return 0;` in `main`:

```c++
cp::check(0 == size_add_cost('M'));
cp::check(30 == size_add_cost('L'));
cp::check(50 == size_add_cost('X'));
cp::println("All Task 2 tests passed.");
```

Run your program. Make sure you get the output:
```sh
All Task 1 tests pass.
All Task 2 tests pass.
```

### Task 3

Now, add the following lines after `cp::println("All Task 2 tests pass.");` and before `return 0;` and run the program:

```c++
cp::check(20 == toppings_cost('R'));
cp::check(50 == toppings_cost('C'));
cp::check(80 == toppings_cost('V'));
cp::check(120 == toppings_cost('M'));
cp::println("All Task 3 tests pass.");
```

Make sure you get the output; make changes to your functions if required:
```sh
All Task 1 tests pass.
All Task 2 tests pass.
All Task 3 tests pass.
```

#### Task 4

Finally, compute the cost of the whole pizza. Implement the function `pizza_cost` to match the description.

Add the following test cases below `cp::println("All Task 3 tests pass.");` and above `return 0;` and run the program.

```c++
cp::check(120 == pizza_cost('R', 'M', 'R'), "RMR");
cp::check(150 == pizza_cost('R', 'M', 'C'), "RMC");
cp::check(180 == pizza_cost('R', 'M', 'V'), "RMV");
cp::check(220 == pizza_cost('R', 'M', 'M'), "RMM");
cp::println("All Task 4 tests passed.");
```

The output should be; make changes to your functions if required:

```sh
All Task 1 tests pass.
All Task 2 tests pass.
All Task 3 tests pass.
All Task 4 tests pass.
```

### Task 5

Do you think you have done enough testing? Are you convinced your functions work? Add at least *two* more test cases for Task 4 and run the program again. Make sure they pass.

### Submit

Submit your work *before* the deadline by...

* clicking `Submit` in the Assignment Fetcher, or
* clicking `Push` in your Github Desktop app, or
* running `git push` on the command line.

## Evaluation

### Correctness

Each test case here is worth 1 point. 13 test cases (`cp::check` statements) = 13 points. Adding two more test cases = 2 points. Total 15.

### Good programming practices

You will be evaluated using the following rubric for this. The TAs will manually check your code:

* Use of descriptive variable names: 3 pt
* Declaring and using constants where appropriate: 2 pt

Total 20 pts.

Apart from these, the TAs will give you feedback on some good programming practices. Please pay attention to these comments even if they don't cost you marks in this lab. They will be important later, e.g., in exams, assignments, and other labs.
