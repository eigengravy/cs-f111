[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7548824&assignment_repo_type=AssignmentRepo)
# Lab 03

## Learning objectives

* Testing simple functions
* Comparing two double numbers for equality
* Designing simple functions using existing functions

## Task 1

The given starter code is a replication of what we saw in class:

* A function that computes the area of a rectangle, and
* Three `cp::check` statements that test this function.

Run this code as is and make sure it runs without a failure. (Upon running it, `output.txt` should contain a single line: "All tests passed.")

If you have done this successfully, make a note under `Task 1` in [Answers.md](Answers.md).

### When check fails

Now we will see what happens when `check` fails. Introduce a bug in the `area_rectangle` function by replacing the `*` with a `+`. Running the code will result in an error that you will see in `runtime_err.txt`:

```sh
terminate called after throwing an instance of 'std::logic_error'
  what():  expected 3
Aborted
```

Do you understand what happened?

Make a note in the answers file that you were able to read this error meessage.

Remove the bug from the function and make sure it runs without error.

## Task 2

Now add the following test case before the `cp::print("All tests passed.")`:

```cpp
cp::check(45.6 == area_rectangle(10.0, 4.56), "expected 45.6");
```

Do you think this will run successfully? Note down your answer in the answers file.

Now run the program. You will be surprised to find it fails! Check [runtime_err.txt](runtime_err.txt) for the error message:

```sh
terminate called after throwing an instance of 'std::logic_error'
  what():  expected 45.6
Aborted
```

What happened? Let's try and print the area of rectangle 10.0 x 4.56. Comment out the `cp::check` you just added and add this line instead:

```cpp
cp::println(area_rectangle(10.0, 4.56));
```

Now run the program. What is the output? `output.txt` shows `45.6`. Then why is the `check` failing?

To really understand this mystery, we must learn how double (and float) values are represented in a computer (that will also tell you why they are named `float`s and `double`s). But that is beyond the scope of this course. All we need to know for now is that real numbers may lose precision when represented as doubles. For instance, 4.56 is actually represented as 4.559999, and multiplying it by 10 does not result in 45.6, but a value that is pretty close to it. So although C++ prints the result as 45.6, it knows it's not really 45.6.

Strange, right? That's the reason why we told you to be careful with the `==` operator when dealing with `double`s.

### Compare doubles using a relative error threshold

So what's the work-around? There are several, more advanced solutions, but the following will suffice for now.

We declare that two `double`s are equal if their *relative error* is very small. How small? Well, we set an arbitrary threshold: `cp::EPSILON`.

Add the following function just above `main`:

```cpp
/**
 * @brief Reports if the relative error between the given double values is small enough to be considered equal. `actual` must be non-zero.
 * 
 */
bool equal_enough(double actual, double expected) {
  double relative_error = cp::abs(actual - expected) / cp::abs(actual);
  return relative_error < cp::EPSILON;
}
```

Does the code make sense? Remember, relative error is the ratio of absolute difference in the actual and expected value to the actual value.

Make a note in the answers file on whether you understand the code or not. Feel free to ask your TA if you don't.

Now, replace the buggy `check` statement with:

```cpp
cp::check(equal_enough(45.6, area_rectangle(10.0, 4.56)), "expected 45.6");
```

and run the program. It should pass - check the output file.

You should use this function when comparing two `double`s to avoid unexpected results. Feel free to reuse this function code in your lab/assignment code.

Make a note that you were able to run the program and got the expected output at this stage.

## Task 3

In this task, you will design a new function to compute area of a square given its side.

In [Answers.md](Answers.md), write the steps from the design recipe for this function:

1. Data - input data type
2. Contract and header - a brief description of the function, including any restriction on the input data
3. Examples

The fourth step, Body, and the fifth step, Tests, should be provided in `main.cpp`.

**Note**, this function must make use of `area_rectangle`.

You are not required to write the `/** ... @brief ...*/` comments or any other comments above the function at this point.

### Submit

Submit your work *before* the deadline by...

* clicking `Submit` in the Assignment Fetcher, or
* clicking `Push` in your Github Desktop app, or
* running `git push` on the command line.
