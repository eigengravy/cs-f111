[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7875704&assignment_repo_type=AssignmentRepo)
# Lab07

## Learning Outcomes

- `cp::expect` instead of `cp::check`
- Manipulating lists
- Incremental development
- A peek into the Makefile

## Tasks

### Task 1

In this task, you will learng about the `cp::expect` function that tests a boolean expression and prints to the console "OK" if it is true and "ERROR" if it is false, along with the optional message.

This function is useful in testing our code. It is also in some sense better than `cp::check`, in that it does not stop at the first failure and gives you a comprehensive message about all the test cases at a given point.

Read through the given `task1.cpp`. Do not make any changes at this point.

Run the file and inspect `output.txt`. The first test case, `"fourth_root(0)"` works by fluke! But notice that the program gives you some feedback about the second and third tests instead of crashing like with `cp::check`.

Go ahead and implement the function (you can use `cp::sqrt`) and run the program again till you get "OK"s on all three tests.

### Task 2

First, take a look at the `Makefile`. On line 16, it defines a variable `MAIN`, initialised to `task1`, which is the name of the program we used so far. Change it to `task2`, so that for the rest of this lab, your `task2.cpp` will be compiled and used to run the Lab07.

Now, open `task2.cpp` and complete the following tasks. You can use any constructs introduced in class/lab so far. Feel free to use `cp::println` to debug and develop your code.

#### Task 2a

Implement the function `largest` to matchits description. Make sure all given test cases work. Add at least three more test cases using `cp::expect`.

#### Task 2b

Implement the function `to_string_reverse` to matchits description. Make sure all given test cases work. Add at least three more test cases using `cp::expect`.

## For those who are unable to run the new docker configuration

Others can ignore!

Last week, we updated our docker environment to `0.1.2`. Our previous docker had all the functions we have used so far except these two:

1. You could not initialise a list using `{...}`
2. You could not use `cp::expect`

If you are not able to use the new docker, try rolling back to the older one:

In `Data/docker-compose.yml`, replace line 4 with:

```sh
      image: f20180196/csf111-cp:0.1.1
```

Make sure the indentation is fine.

Now, replace your `main` with:

```cpp
cp::println("testing...");

return 0;
```

and run it.

If it works, proceed. Otherwise, contact Swaroop.

Now, you need to initialise the list like this and use it for testing.

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

Make appropriate changes to your `main` in `task2`.
