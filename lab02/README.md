[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7471148&assignment_repo_type=AssignmentRepo)
# Lab 02: Familiarising yourself with the cp library

## Objectives

In this lab, you will learn about --

* accessing the cp-library documentation
* using basic `cp::print` operation
* the output log on the docker environment

We assume you have already set your working environments according to the  instructions.

## Understanding the given files

Using the VS Code extension you have configured, download this starter code. (If you are reading this in VSCode, you have already done this step.)

First, look at the contents of the folder. This is the general structure for all the labs and assignments in this course (with minor modifications).

```sh
├── Answers.md
├── Data
├── Makefile
├── README.md
├── cp-0.1.0-Linux
├── errors.txt
├── main.cpp
└── output.txt
```

Let's look at each one of these.

1. `Answers.md` is where you will write answers to specific questions in a lab/assignment.
2. `Data/` contains the configurations for running your program on the underlying docker instance. **Do not make any changes** to the contents of this folder.
3. `Makefile` is a program that is invoked when you click the **Run** button in VS Code. We will not go into how it compiles and executes your code at this point. Again, make **no changes to the Makefile**.
4. `README.md` is this file. In each lab/assignment, this is where you must start. Make a habit of reading the README file thoroughly.
5. `cp-0.1.0-Linux/` contains our library. **TODO**
6. `errors.txt` is empty, and ideally should remain empty. It's where we record any compile-time errors your code may cause.
7. `main.cpp` is where you will write your code. We will come back to what you are expected to do in this lab soon.
8. `output.txt` is where we capture what you would see on the console if you run this program outside docker. Instead of seeing the output on the terminal, you will see it here. Make a habit of checking this file after you run your program.

## First program

The given starter code in `main.cpp` looks like this:

```cpp
#include <cp/cp.hpp>

int main() {
  cp::print("My first program.");
  cp::print(42);

  return 0;
}
```

You have already seen this code in class. Go ahead and start docker (by turning on the button under "Assignment Fetcher") and click "Run".

**Q.1**: Check the output in `output.txt`. Does it match your expectation/understanding? **Note down your answer in Answers.md**

## Modifying the program

Remember the discussion in class about `cp::print` taking different *types* of values? We already have it printing a `cp::string` and an `int`. Write at least one statement for printing a `char`, a `double`, and a `bool`. Run the program again.

**Q.2:** Does the output match your expectation? **Note down your answer in Answers.md**

## Exploring the library

The `cp::print` instruction is coming from our library. Let's check what the *documentation* of this instruction says.

* Go to the course web page.
* Scroll down to the section "CP Library" and click the link: <http://swaroopjoshi.in/courses/cp-library/>. You can bookmark this link for quick access.
* Type `print` in the search box on the left and hit enter. It will show you `print` and `println`.
* Expand the first one. It will show you three options. Choose the middle one: `cp::print(auto value)`.
* Read the description: "Prints the given value to the console."

**Q.3**: `print` was rather simple and straightforward. Explore the library documentation and visit at least three other functions. Does the description of these functions make sense? Tell us in `Answers.md`.

It's perfectly fine if they don't - but put in the efforts and ask questions to your TAs. Very soon, you will be pros in making sense of the documentation!

## Errors

We have talked about three types of errors in class.

**Q.4:** Try out the three examples from slides and note down what you observe. Did you or did you not get the errors as expected? Make a note in `Answers.md`.
