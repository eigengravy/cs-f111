[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8021992&assignment_repo_type=AssignmentRepo)
# Lab11

## Learning Outcomes

- Some basic operations using regular C++

## Tasks

### Task 0

Note a couple of things in the starter code:

1. `main.cpp`: There's no `#include <cp/cp.hpp>`. We are including `iostream` which takes care of input/output in the standard C++.
2. A fallout of that is seen in `main`. `std::cout` and `std::cin` replace `cp::print` and `cp::read` variants.
3. `Makefile`: the `LIB = cp` line is removed. You will also see changes similar to Lab10, the one we used for user input from the command line.

Now, let's look into the `main`.

Note how `std::cout` and `std::cin` don't appear like functions (although they are, but they appear so due to some tricks in C++). Notice the direction of the `<<` and `>>`. With `cout`, it goes to the right, with `cin`, to the left.

Our `main` begins with prompting for a `std::string` from the user and then an integer that will be the numbere of characters to left-shift the string.

Also notice how we can chain strings and integers and characters together to `cout`.

Go to the docker tab, then attach shell, and run `make`, like you did in Lab10. It should prompt you for a string and an integer.

Here is a sample run:

```sh
./Lab11 
Enter a word or a line: bits
Enter a positive integer: 1
Rotating 'bits' left by 1 gives ''
```

### Task 1

Study the given starter code carefully, ask questions of your TAs *and peers* if needed, and then implement the `rotate_left` function. You can create as many helper functions as you want.

How will you test your program? We no longer have `cp::expect`. Run and print the output as shown and manually compare it.

You can use any functions on `std::string` -look up [here](https://en.cppreference.com/w/cpp/string/basic_string)- although you probably won't need much beyond the `operator[]`, `operator+` (which now takes `char`s as well), etc.

Look how complicated the documentation is! And it's understandable because it deals with so many variants of each function and its target audience is professionals. We deliberately simplified things so students could focus only on the relevant details.

Here are some sample runs:

```sh
./Lab11 
Enter a word or a line: bits
Enter a positive integer: 1
Rotating 'bits' left by 1 gives 'itsb'
```

```sh
./Lab11 
Enter a word or a line: bits
Enter a positive integer: 2
Rotating 'bits' left by 2 gives 'tsbi'
```

```sh
./Lab11 
Enter a word or a line: bits
Enter a positive integer: 8
Rotating 'bits' left by 8 gives 'bits'
```

### Task 2

Once you are convinced it works for all the positive integers, allow it to take negative integers, where rotating by a negative integer left is same as rotating by the same offset right.

Here are some sample runs:

```sh
./Lab11 
Enter a word or a line: bits
Enter an integer: -1
Rotating 'bits' left by -1 gives 'sbit'
```

```sh
./Lab11 
Enter a word or a line: bits
Enter an integer: -2
Rotating 'bits' left by -2 gives 'tsbi'
```
