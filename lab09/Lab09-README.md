# Lab09 Enums

## Learning Outcomes

- Practice with enums

## Tasks

This lab is rather free-form. Tasks are not marked out like before. You have five function headers. And one `expect` test for each of them. Implement each function and add at least two more test cases for each. The functions descriptions are self-explanatory.

Note, for the `kth_day` function, you can write a long `if`-`else` chain (if `k` is 1, then it's `day::mon`, if `k` is 2, then it's `day::tue`, etc.). Or, you can make a clever use of C/C++ abilities to convert integral data types between one another by simply type-casting.

Type casting is when you explicitly tell the compiler to treat a data type as another data type. If the compiler can do it, it does so (without an error message -or even a warning-  in most cases). 

We type-casted `signal` to `int` yesterday in class.

You can do the reverse by type-casting an `int` to a `day` now. For instance, the expression `day(1)` will evaluate to `day::mon`.

Be very careful with these, though. The compiler does not check if the integer you are type-casting from is a *valid* integer for the enum. For example, it won't complain if you try to typecast 17 to a day! It is *your* responsibility to make sure invalid values are not typecast to enums.
