[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7986602&assignment_repo_type=AssignmentRepo)
# Lab10

## Learning Outcomes

- Processing user input

## Tasks

We started talking about user inputs in the last class. Things get tricky when we give our users power to interact with the program. But any meaningful program must let them do it! In this lab, you will learn and demonstrate how to validate an input and how to take repeated inputs.

Read the `main` carefully. For now,

- `cp::read_line` returns a string from the terminal till the user hits enter
- `read_valid_cgpa` returns a double from the terminal

Without running the `main`, try to predict its behaviour. How many student name and cgpa's can it take?

### Task 0

How to run programs that interact with users?

First and foremost: **Do NOT click the Run button!** It will keep showing the "Compiling and Running" dialog forever!

We need to run such programs from the command line.

1. Open the docker tab in VSC
2. In the containers view, right click on the container under "data" and click "Attach shell".
3. It should open the terminal at the bottom.
4. Type `make` and hit enter.
5. Repeat only step 4 next time if the terminal is already running.

### Task 1

Does it produce the expectd output for the highest cgpa?

Your first task is to fix it by making appropriate changes to the `while` loop in `main`. Feel free to add new variables and functions and constructions like `if` and `while`. But do not change the `report_highest` function. It is simply supposed to print the name and cgpa pair it is given. Do not use any structures or lists for this task.

### Task 2

What stops a user from entering a negative number for the CGPA? Our program should ensure such values are not accepted. Make appropriate changes to the `read_valid_cgpa` function so it matches its description. Here is a sample (partial) run of the program where it handles the invalid inputs:

```sh
Enter student's name: ajit
Enter student cgpa: -3
Invalid input; try again: 12
Invalid input; try again: 8.5
Do you want to add another student? (y/n) 
```

### Invalid inputs we won't handle

There still are inputs we cannot handle. For instance if the user enters letters when expecting numbers, our program will crash.

It's not terribly difficult to handle such inputs, but we will not bother with such cases at this stage.
Crashing the program is acceptable behaviour!

### Functions to read data from the terminal

Look at these functions in our [library](https://swaroopjoshi.in/courses/cp-library/namespacecp.html#ad122abe49b589b27b291e3d9aaed440b):
- read_int
- read_char
- read_bool
- read_double
- read_line

You can use them in any program for taking input from the user.
