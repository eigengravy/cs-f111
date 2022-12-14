[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7737835&assignment_repo_type=AssignmentRepo)
# Lab 05

## Learning Objectives

* Using simple `while` loops
* Incrementally developing and testing your solutions

## Starting point

The starter code contains skeletons for four functions you will implement and the driver function `main`. (This is a non-evaluative lab.)

## Tasks

Use only the `while` loop discussed in class. Do not use constructs not yet discussed in class. When in doubt, ask your TAs. Make best use of the functions you have developed wherever possible. Remove the `// TODO` comment once done.

### Task 1

You will implement a function `gcd` that takes two positive integers and returns their greatest common divisor using the following logic:

1. Start with the lower of the two integers.
2. If it divides both the numbers, it is the GCD.
3. Otherwise, decrement it by one. Repeat until you have tried with every number down to 1.

For instance, to compute the GCD of 8 and 12, start with 8. Since it does not divide 12 and 8 both, check 7. Since it does not divide 12 and 8 both, check 6. Then 5 and then 4. Since 4 divides both 12 and 8, 4 is their GCD.

#### Task 1a

Let's break this down into multiple subtasks. First, we need to find out which is the smaller of the two functions. Implement the function `min` to fulfil the given description in the starter code.

Run the code to test this implementation.

#### Task 1b

Now, implement the function `is_divisible` to match its description. Add the testcases (`cp::check` statements) based on the documentation of the function. Add at least two more test cases of your own.

#### Task 1c

Now implement the `gcd` function to match its description. Add the testcases baseed on the documentation of the function. Add at least two more test cases of your own.

### Task 2

Now implement the function `is_prime` that takes an integer and reports if it is prime or not. Recall, prime numbers are integers greater than 1 that are not divisible by any other integer. Make sure you use one or more functions you created in one of the Tasks.

Add the testcases baseed on the documentation of the function. Add at least two more test cases of your own.
