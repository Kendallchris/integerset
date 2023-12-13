[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-8d59dc4de5201274e310e4c54b9627a8934c3b88527886e3b421487c677d23eb.svg)](https://classroom.github.com/a/wPAFmocQ)
# Dynamic IntegerSet

In this assignment you are expected to implement the methods of the class `IntegerSet`. These methods represent several operations on sets.

## Goal
The goal of the programming assignment is to implement the methods of the class `IntegerSet`, additionally you are expected to write the appropriate header comments to each one of the methods. Once you have *correctly* implemented them you will pass the 30 tests that are given to you in the `test.cpp` file.


This lab will help you practice the following topics:
* Working with tests
* Working with multiple source code files
* Working with arrays
* Working with Dynamic Memory
* Checking for Memory Leaks
* Working with classes
    * Constructors
    * Destructors
    * Copy Assignment Operator
    * Methods
    * const Methods
    * const Return types

## The `IntegerSet` class

### Data Members

* `bool* _elements`
   > The pointer to the first element of a dynamically allocated array of `bool`. The number of elements of this array is going to be given by the user in the constructor.
* `size_t _size` 
   > Represents the number of elements the set can hold. The set is going to be able to hold integers from `0` to `_size - 1`. This member basically sets the universe for the set instance.

### Methods

* `IntegerSet(size_t size)`
  > Constructor of the class, sets `_size` to `size` and initializes the set to an empty set.
* `IntegerSet(size_t size, int* elements)`
  > Constructor of the class. This constructor's `size` parameter **is not** the `_size` member of the class. Instead, it represents the number of integers in the array `elements`. This constructor will work as follows:
    ```c++
        int values[] = {9, 4, 0, 2};
        IntegerSet set(4, values);
    ```
  > Creates a set with the following elements `{0, 2, 4, 9}`. You will need to determine the correct value for `_size`, and then allocate the array of `bool` and then set the elements of the set appropriately according to the values of the int array.   
* `IntegerSet(const IntegerSet& set)`
  > Copy constructor for the class. Remember, you are dealing with dynamic memory, make sure to make a deep copy.
* `~IntegerSet()`
  > Destructor, deallocates the dynamically allocated memory.
* `const IntegerSet& operator=(const IntegerSet& rhs)`
  > Copy assignment operator for the class. Remember, you are dealing with dynamic memory, make sure to make a deep assignment.
* `ostream& Write(ostream& output)const`
  > Writes the elements of the set to `output`. It will output the values of the elements separated by spaces. The last element will also have a space after it. For example, for the set shown in the second constructor, it would be output as: `0 2 4 9 ` with a space after the 9.
* `istream& Read(istream& input)`
  > Reads the elements from input. You don't know what elements are coming!
* `IntegerSet Union(const IntegerSet& rhs)const`
  > Calculates the union by `this` and `rhs`. For example: if you had sets `A = {1, 3, 6}` and `B = {2, 5}` then `A.Union(B)` would return a new set with the following elements `{1, 2, 3, 5, 6}`.
* `IntegerSet Intersection(const IntegerSet& rhs)const`
  > Calculates the intersection by `this` and `rhs`. For example: if you had sets `A = {1, 3, 6}` and `B = {2, 3, 5}` then `A.Intersection(B)` would return a new set with the following element `{3}`.
* `IntegerSet Complement()const`
  > Calculates the complement of the set represented by `this`. It will return a new set with the elements not in `this` and without those in `this`. For example: if you had `A = {1, 3}` for a set with `_size = 5`, then `A.Complement()` would return a new set with the following elements `{0, 2, 4}`. Think about this: Was it necessary to say what the `_size` value was for this example?
* `bool Belongs(size_t element)const`
  > Checks if the parameter `element` is in the set. Returns true if it is in the set, false otherwise.
* `bool AddElement(size_t element)`
  > Adds the element represented by the parameter. If the element can be added (it belongs to the universe of `this`) then it is added and the method returns `true`, it returns `false` otherwise.
* `void Clear()`
  > Makes `this` an empty set.
* `string ToString()const`
  > Returns a string representation of the set. For example: `A = {0, 3, 4}` when calling `A.ToString()` will return `{0, 3, 4}` as a string. Note that there are spaces after the commas.
* `string ToJSON()const`
  > Returns a [JSON](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/JSON) representation of the set. For example `A = {0, 2, 3}` when calling A.ToJSON() will return `{"set": [0, 2, 3]}`. Note there are spaces after the commas.
* `bool Equals(const IntegerSet& rhs)const`
  > Determines if `this` and `rhs` are the same set.
* `bool IsEmpty()const`
  > Returns `true` if the `this` does not have any elements, `false` otherwise.
* `string CartesianProduct(const IntegerSet& rhs)const`
  > Implementing this method is **extra credit**. The first challenge is to research what the cartesian product of two sets is. Then you may check the test to see the format of the result. No further explanation will be given for this method. If you don't implement it there will be no deductions, however to get the extra credit you must pass the other 30 tests!

### The set representation
The set is represented with a dynamically allocated array of `bool` called `_elements`. The arrays have an associated `_size`. This size represents the universe of the set, that is the possible elements that the set can hold.

For example:
```c++
    bool a[5] = {false, true, false, true, true};
    bool b[10] = {false};
```
The previous two declarations would represent two sets `a` and `b`. In the case of set `a` its universe is $U=\\{0,1,2,3,4\\}$, and in the case of `b` its universe is $U=\\{0,1,2,3,4,5,6,7,8,9\\}$. The universe is determined by the size of the array, the size of the array *does not* represent the elements but what elements **could** be in the set. So the actual sets would be $a=\\{1,3,4\\}$ and $b=\\{\\}$. `a` has elements 1, 3 and 4 because `a[1]`, `a[3]`, and `a[4]` are true, meaning that those elements are in the set. In the case of `b` it is the empty set because all its elements are set to `false`.

The above description is based on "fixed" size arrays, your assignment is to use dynamically allocated arrays within the class `IntegerSet`.

## A sample run

```c++
IntegerSet a(5);

cout << a.AddElement(3) << endl;    // prints true
cout << a.AddElement(1) << endl;    // prints true
cout << a.AddElement(10) << endl;   // prints false
cout << a.ToString() << endl;       // prints {1, 3}
a.Write(cout) << endl;              // prints 1 3
// there is a space after the three

IntegerSet b(5), c(5);
b.AddElement(4);
b.AddElement(1);

c = a.Intersection(b);
cout << c.ToString() << endl;       // prints {1}
c = a.Union(b);
cout << c.ToString() << endl;       // prints {1, 3, 4}

cout << c.ToJSON() << endl;         // prints {"set": [1, 3, 4]}

```
## Files you are given
- `main.cpp` in this file you can write your own tests as you are coding your class. This file will not be graded. Consider it like a sandbox for testing.
- `test.cpp` this file contains the `main` and `Test` functions. **DO NOT** modify this file in any way. The `main` function will execute 30 tests on the operations that you are requested to implement. An additional test will be executed to check for `CartesianProduct`. 
- `integer_set.h` this file contains the declaration of the `IntegerSet` class. **DO NOT** modify this file in any way.
- `integer_set.cpp` on this file you will work. In this file you will write the implementation of all the methods declared in `integer_set.h`. You may add helper functions, but you _must_ implement the methods that are declared in the header file as they are. You will need to add the appropriate header comments and other comments in your code.
- `CMakeLists.txt` this file contains the instructions for the compiler on how to build your program. **DO NOT** modify this file in any way. By default, this will compile your program using the `main.cpp` file. To compile using `test.cpp`... you will need to use the command line! 
- `makefile` this file contains the instructions to compile your project from the command line. Using this file you will be able to compile your program to produce the executable for the test and also for the main.
## Possible Steps
You should take a look at the `main` function and discern from there in what order you should implement the methods.

> Remember to make sure your code compiles.

## Expected Output
```
TEST PASSED (01 - IsEmpty                                      ) Total Passed: 1
TEST PASSED (02 - Belongs(0)                                   ) Total Passed: 2
TEST PASSED (03 - Belongs(1)                                   ) Total Passed: 3
TEST PASSED (04 - Belongs(2)                                   ) Total Passed: 4
TEST PASSED (05 - Belongs(3)                                   ) Total Passed: 5
TEST PASSED (06 - Belongs(4)                                   ) Total Passed: 6
TEST PASSED (07 - Belongs(5)                                   ) Total Passed: 7
TEST PASSED (08 - ToString                                     ) Total Passed: 8
TEST PASSED (09 - ToJSON                                       ) Total Passed: 9
TEST PASSED (10 - Complement                                   ) Total Passed: 10
----------------------------------------------------------------------------------
TEST PASSED (11 - Successful AddElement                        ) Total Passed: 11
TEST PASSED (12 - Successful AddElement                        ) Total Passed: 12
TEST PASSED (13 - Successful AddElement                        ) Total Passed: 13
TEST PASSED (14 - Unsuccessful AddElement                      ) Total Passed: 14
TEST PASSED (15 - ToString                                     ) Total Passed: 15
TEST PASSED (16 - ToJSON                                       ) Total Passed: 16
TEST PASSED (17 - Equals & Copy Constructor                    ) Total Passed: 17
TEST PASSED (18 - ToString                                     ) Total Passed: 18
TEST PASSED (19 - Not an Empty Set                             ) Total Passed: 19
TEST PASSED (20 - Empty after Clean                            ) Total Passed: 20
----------------------------------------------------------------------------------
TEST PASSED (21 - Equals and Array Constructor                 ) Total Passed: 21
TEST PASSED (22 - ToString and Array Constructor               ) Total Passed: 22
TEST PASSED (23 - Equals and Complement                        ) Total Passed: 23
TEST PASSED (24 - ToString and Complement                      ) Total Passed: 24
TEST PASSED (25 - ToString and Read                            ) Total Passed: 25
TEST PASSED (26 - ToString and Write                           ) Total Passed: 26
TEST PASSED (27 - Input outside of universe                    ) Total Passed: 27
TEST PASSED (28 - ToString and Union                           ) Total Passed: 28
TEST PASSED (29 - ToString and Intersection                    ) Total Passed: 29
TEST PASSED (30 - Cascade, Intersection and Complement         ) Total Passed: 30
----------------------------------------------------------------------------------
TEST PASSED (99 - Cartesian Product                            ) Total Passed: 31
```

## Compiling, Running and Memory Leak Checking from the Command Line
The text below shows how to:
* Add all programs to the test with "g++ -o test_program test.cpp dlinkedlist.cpp vsarray.cpp sorted_double_linked_list.cpp integer.cpp person.cpp list.cpp object.cpp comparable.cpp"
* Show the contents of the directory: `ls`
* Make your test executable: `make test`. Notice that in the output it shows what files it is compiling and that there are no warnings or compilation errors.
* Run your test: `./test`. Note that this is passing all 31 tests.
* Check for memory leaks: `valgrind --leak-check=full ./test`. This will call `valgrind` and asks it to check for all possible leaks for the program `./test`. Note below that it reports 0 errors and in the heap summary says that at exit there are 0 bytes in 0 blocks. You need to make sure you don't have any memory leaks.
  > `in use at exit: 0 bytes in 0 blocks` 

  > `ERROR SUMMARY: 0 errors from 0 contexts`


```
root@0e42e627fe9c:/development/CSC2431/dynamic-integerset-solution# ls
CMakeLists.txt  README.md  cmake-build-debug  integer_set.cpp  integer_set.h  main.cpp  makefile  test.cpp
root@0e42e627fe9c:/development/CSC2431/dynamic-integerset-solution# make test
g++ -c test.cpp -o test.o -std=c++14 -Wall -g
g++ -c integer_set.cpp -o set.o -std=c++14 -Wall -g
g++ test.o set.o -o test -std=c++14 -Wall -g
root@0e42e627fe9c:/development/CSC2431/dynamic-integerset-solution# ./test
TEST PASSED (01 - IsEmpty                                      ) Total Passed: 1
TEST PASSED (02 - Belongs(0)                                   ) Total Passed: 2
TEST PASSED (03 - Belongs(1)                                   ) Total Passed: 3
TEST PASSED (04 - Belongs(2)                                   ) Total Passed: 4
TEST PASSED (05 - Belongs(3)                                   ) Total Passed: 5
TEST PASSED (06 - Belongs(4)                                   ) Total Passed: 6
TEST PASSED (07 - Belongs(5)                                   ) Total Passed: 7
TEST PASSED (08 - ToString                                     ) Total Passed: 8
TEST PASSED (09 - ToJSON                                       ) Total Passed: 9
TEST PASSED (10 - Complement                                   ) Total Passed: 10
----------------------------------------------------------------------------------
TEST PASSED (11 - Successful AddElement                        ) Total Passed: 11
TEST PASSED (12 - Successful AddElement                        ) Total Passed: 12
TEST PASSED (13 - Successful AddElement                        ) Total Passed: 13
TEST PASSED (14 - Unsuccessful AddElement                      ) Total Passed: 14
TEST PASSED (15 - ToString                                     ) Total Passed: 15
TEST PASSED (16 - ToJSON                                       ) Total Passed: 16
TEST PASSED (17 - Equals & Copy Constructor                    ) Total Passed: 17
TEST PASSED (18 - ToString                                     ) Total Passed: 18
TEST PASSED (19 - Not an Empty Set                             ) Total Passed: 19
TEST PASSED (20 - Empty after Clean                            ) Total Passed: 20
----------------------------------------------------------------------------------
TEST PASSED (21 - Equals and Array Constructor                 ) Total Passed: 21
TEST PASSED (22 - ToString and Array Constructor               ) Total Passed: 22
TEST PASSED (23 - Equals and Complement                        ) Total Passed: 23
TEST PASSED (24 - ToString and Complement                      ) Total Passed: 24
TEST PASSED (25 - ToString and Read                            ) Total Passed: 25
TEST PASSED (26 - ToString and Write                           ) Total Passed: 26
TEST PASSED (27 - Input outside of universe                    ) Total Passed: 27
TEST PASSED (28 - ToString and Union                           ) Total Passed: 28
TEST PASSED (29 - ToString and Intersection                    ) Total Passed: 29
TEST PASSED (30 - Cascade, Intersection and Complement         ) Total Passed: 30
----------------------------------------------------------------------------------
TEST PASSED (99 - Cartesian Product                            ) Total Passed: 31
root@0e42e627fe9c:/development/CSC2431/dynamic-integerset-solution# valgrind --leak-check=full ./test
==137== Memcheck, a memory error detector
==137== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==137== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==137== Command: ./test
==137==
TEST PASSED (01 - IsEmpty                                      ) Total Passed: 1
TEST PASSED (02 - Belongs(0)                                   ) Total Passed: 2
TEST PASSED (03 - Belongs(1)                                   ) Total Passed: 3
TEST PASSED (04 - Belongs(2)                                   ) Total Passed: 4
TEST PASSED (05 - Belongs(3)                                   ) Total Passed: 5
TEST PASSED (06 - Belongs(4)                                   ) Total Passed: 6
TEST PASSED (07 - Belongs(5)                                   ) Total Passed: 7
TEST PASSED (08 - ToString                                     ) Total Passed: 8
TEST PASSED (09 - ToJSON                                       ) Total Passed: 9
TEST PASSED (10 - Complement                                   ) Total Passed: 10
----------------------------------------------------------------------------------
TEST PASSED (11 - Successful AddElement                        ) Total Passed: 11
TEST PASSED (12 - Successful AddElement                        ) Total Passed: 12
TEST PASSED (13 - Successful AddElement                        ) Total Passed: 13
TEST PASSED (14 - Unsuccessful AddElement                      ) Total Passed: 14
TEST PASSED (15 - ToString                                     ) Total Passed: 15
TEST PASSED (16 - ToJSON                                       ) Total Passed: 16
TEST PASSED (17 - Equals & Copy Constructor                    ) Total Passed: 17
TEST PASSED (18 - ToString                                     ) Total Passed: 18
TEST PASSED (19 - Not an Empty Set                             ) Total Passed: 19
TEST PASSED (20 - Empty after Clean                            ) Total Passed: 20
----------------------------------------------------------------------------------
TEST PASSED (21 - Equals and Array Constructor                 ) Total Passed: 21
TEST PASSED (22 - ToString and Array Constructor               ) Total Passed: 22
TEST PASSED (23 - Equals and Complement                        ) Total Passed: 23
TEST PASSED (24 - ToString and Complement                      ) Total Passed: 24
TEST PASSED (25 - ToString and Read                            ) Total Passed: 25
TEST PASSED (26 - ToString and Write                           ) Total Passed: 26
TEST PASSED (27 - Input outside of universe                    ) Total Passed: 27
TEST PASSED (28 - ToString and Union                           ) Total Passed: 28
TEST PASSED (29 - ToString and Intersection                    ) Total Passed: 29
TEST PASSED (30 - Cascade, Intersection and Complement         ) Total Passed: 30
----------------------------------------------------------------------------------
TEST PASSED (99 - Cartesian Product                            ) Total Passed: 31
==137==
==137== HEAP SUMMARY:
==137==     in use at exit: 0 bytes in 0 blocks
==137==   total heap usage: 66 allocs, 66 frees, 77,169 bytes allocated
==137==
==137== All heap blocks were freed -- no leaks are possible
==137==
==137== For lists of detected and suppressed errors, rerun with: -s
==137== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
root@0e42e627fe9c:/development/CSC2431/dynamic-integerset-solution#
```

## Grading
The number of test you need to pass is 30, if you pass them all then your _raw_ grade will be 100, this is assuming you don't get any deductions on good programming practices. If you pass 15 tests, then your _raw_ grade would be $15/30 * 100 = 50$.

## Deductions

* For each infraction on good programming practices there will be a deduction of 5 points
* If the program has a runtime error (the program crashes) there will be a deduction of 10 points
* If the program has memory leaks (checked by valgrind) there will be a deduction of 10 points
* If the program does not have comment headers there will be a deduction of 5 points
* If the program does not have comments on functions and appropriate additional comments there will be a deduction of 5 points
* If the program does not follow instructions, for instance if you did not implement any of the requested functions, there will be a deduction of 5 points per ignored instruction
* If the program does not compile, the grade will be zero.

NOTE: Remember to check the Canvas Page about Programming Practices and the course coding conventions.


## Academic Integrity

This programming assignment is to be done on an **individual** basis. At the same time, it is understood that learning from your peers is valid, and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.

Hence, the following guidelines are established:
* Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
* Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem-solving: control the urge to show them what to do by writing the code for them.
* If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
* **If there is any evidence that a program or other written assignment was copied from another student (or from any source), neither student will receive any credit for it. This rule will be enforced: It is possible to fail the class for cheating on a programming assignment.**
* Protect yourself: Handle throw-away program listings carefully.
* Remember to read the Academic Integrity guidelines provided in the class syllabus.
* DO NOT copy code from any source, **ALL** the submitted code should be written by you (except the code that is given).
