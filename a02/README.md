[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7925393&assignment_repo_type=AssignmentRepo)
# A2 - sets

## Learning Outcomes

- Manipulating lists
- Practice with structures
- Incremental development
- Developing data structures using existing constructs

## Tasks

### Task 0

Programming is an art of representing complex real-world concepts using the programming constructs at your disposal. We have so far used basic scalar data like `int`, `bool`, etc., and compound data like `list` and `struct`. In this assignment, you will implement a *set of integers* using `list`s.

When we design a new data, we are primarily concerned about two things:

1. how to represent the data using the existing constructs
2. how to perform the basic operations on the data using the existing constructs

The first one is given for you in this assignment.

Look at the `struct` at the top of the main file:

```cpp
/**
 * @brief Represents a set of integers. No duplicate values. No specific order.
 * 
 */
struct set_int {
  cp::list_int value;
};
```

Make sure you understand what this means. We are creating a new type `set_int` where we store the elements as a list of integers. It means, when you implement the operations on the set, you will invoke appropriate methods on the underlying list.

Note, sets do not have duplicate elements. For instance, the set of natural numbers has exactly one `1` in it. Moreover, the order of elements in a set does not matter: `{1, 2, 3}` is the same as `{3, 2, 1}` or `{1, 3, 2}` or any other combination. Preserve these semantics in your implementation.

What are some common operations on a set?

- size
- membership (whether x is in the set S)
- insert / delete an element
- interection and union of two sets

Take a look at the given headers for functions representing all these operations.

### Task 1

Go through the `main` code and make sure you understand what it means.

`to_string` is implemented for you. Run `main` and check the result of these two print statements:

```cpp
  cp::println(to_string(&first));
  cp::println(to_string(&second));
```

Remember, you cannot rely on the order of elements, but it is good to be able to see a string representation of the set.

Secondly, see how the `to_string` implementation uses the underlying `list`. You should do something similar when implementing the other operations.

### Tasks 2-7

Implement the functions in each task as indicated by the print statements in `main`. Test them using the given `expect` statements. Add at least two testcases of your own for each function.
