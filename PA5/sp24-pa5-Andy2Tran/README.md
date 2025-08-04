[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/u_yNa7NC)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=14281096)
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">

# Programming Assignment #5 (PA5)

## Overview

In this assignment, we take a look at the array and vector data structures.

<div
    style="background-color: #FFFBEB; border-left: 6px solid #F97316; color: #813F0B; padding: 10px; border-radius: 5px;">
    <i class="fa-solid fa-triangle-exclamation" style="margin-right: 10px;"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Naming Conventions:</b>
    <p><ul>
<li>While implementation details are still up to you, make sure you use the coding style discussed in class regarding functions, name, classes, and indentations unless a specific name is given to you throughout this assignment.</li>
<li>If a specific name for something like a <code>variable</code>, <code>class</code>, or <code>function</code> is given to you, you <em>MUST</em> use it exactly or the autograder won&#39;t be able to find it and the tests will fail.<ul>
<li>This applies to function prototypes/signatures/definitions as well. The <code>inputs</code> and <code>outputs</code> of the functions you implement must also match the ones specified.</li>
<li>Points will <em><em>not</em></em> be given for tests that fail due to incorrect naming or signature mismatch.</li>
</ul>
</li>
<li>Variables should be localized with the correct scope, datatype (based on the data needed to be stored), and their names must be pneumonic. I.e., avoid variables like a, b, i, j, k, x, y, z, etc. </li>
<li>Coding style will be reviewed and your assessment grade may be impacted due to that as described in our syllabus.</li>
<li>Remember that homework must be completed <strong>individually</strong> without help (human or AI).</li>
</ul></p>
</div>

<br>

<!-- Restrictions on what libraries are/aren't allowed to be used -->
<div
    style="background-color: #FEF2F2; border-left: 6px solid #EF4444; color: #991B1B; padding: 16px; border-radius: 5px;">
    <i class="fa-solid fa-fire-flame-curved" style="margin-right: 10px;"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Restrictions:</b>
    <p><ul>
<li>Only the libraries discussed in class can be used in homework:<ul>
<li><code>iostream</code></li>
<li><code>string</code></li>
<li><code>cmath</code></li>
<li><code>random</code></li>
<li><code>ctime</code></li>
<li><code>array</code></li>
<li><code>vector</code></li>
<li><code>cstddef</code></li>
<li><code>iomanip</code></li>
<li><code>exception</code></li>
<li><code>cstdlib</code></li>
</ul>
</li>
<li>The <code>using namespace</code> statement such as <code>using namespace std;</code> is <strong>not allowed</strong> in this homework. The <code>using</code> keyword is otherwise allowed, e.g., <code>using std::cout;</code>.</li>
<li>You can assume certain frequently used keywords, like string, array, and vector are being accessed this way if you don't see the <code>std::</code> in front of it.</li>
</ul></p>
<p>You may lose a significant number of points for not following these restrictions!</p>
</div>

## Tasks & TODOs

<!-- Note (Blue) -->
<div
    style="background-color: #E5F6FF; border-left: 6px solid #2CA5E0; color: #091E42; padding: 16px; border-radius: 5px; font-family: Arial, sans-serif; font-size: 14px;">
    <i class="fa-solid fa-circle-info"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Note:</b>
    <p>There are no TODO comments for this assignment as you are creating your own files. You can use the TODOs from prior PAs as a rough guide to the pieces you need. You should also refer to your class notes and textbook for guidance as necessary.</p>
</div>

<br>

---

## Part 1: Array Functions

You will create a series of functions to fill an array, print an array, check if there are duplicates in an array and sort an array, every parameter will be [pass-by-reference](https://www.ibm.com/docs/en/zos/2.4.0?topic=calls-pass-by-reference-c-only).

1. In the `src` directory, create `useArray.cpp` and `useArray.h` files
  - the `.h` file must contain only the declarations (prototypes).
  - the `.cpp` file must contain the implementation of the functions.
  - **Do not be using a class for this part**
  - Don't forget everything in C++ is case-sensitive. This includes file names.
2. Functions in `useArray`
  - `howMany()`
    - Returns an int entered from the keyboard. This integer tells the program how many numbers to generate(no more than 100). If the number doesn't meet the requirement, throw an exception of type const char* with message: "The input does not meet the requirements".
  - `fillArray(array<int,MAX_SIZE>&, int&)`
    - Will receive an empty array of ints passed by reference to be populated with random values, with MAX_SIZE = 100, and an int passed by reference, which is a number between 1 and 100 of random values to generate. If the value is less than 1 or more than 100, the function will terminate without any values being added to the array. The random values must be between 0 and 9999. You must use the srand() method in this function to seed the random values. This function will not return anything
  - `printArray(array<int,MAX_SIZE>&, int&)`
    - Will receive a populated array of ints passed by reference, and an int of the array length passed by reference. It will display the array 10 numbers per row. Each value is delimited by a space. This function will not return anything.
  - `dupeCheck(array<int,MAX_SIZE>& , int&)`
    -  Will receive a populated array of ints passed by reference, and an int of the array length passed by reference. This function will check if the Array Contains any Duplicates.This function return a bool. if array contains any duplicates, return false. Otherwise return true.
  - `sortArray(array<int,MAX_SIZE>&, int&)`
    -  Will receive a populated array of ints passed by reference, and an int of the array length passed by reference. This function will arrange the elements of the array in ascending order. This function will not return anything
    - Compare two consecutive elements of the array and swap if the lower indexed element is larger than the smaller indexed element.

          Ex.  the array is 3, 2, 1, 4, 6, 9
            First pass
              Compare 3, 2.  The array becomes 2, 3, 1, 4, 6, 9
              Then compare the next pair 3, 1 the array becomes 2, 1, 3, 4, 6, 9
              Compare 3, 4. No change to the array
              Compare 4, 6. No change to the array
              Compare 6, 9. No change to the array

            Second pass the array is now 2, 1, 3, 4, 6, 9
              Compare 2, 1. The array becomes 1, 2, 3, 4, 6, 9
              Comapre 2, 3. No change
              Compare 3, 4. No change
              Compare 4, 6. No change
              Compare 6, 9. No change.

            Third pass the array is now 1, 2, 3, 4, 6, 9
              Compare 1, 2. No change
              Compare 2, 3. No change
              Compare 3, 4. No change
              Compare 4, 6. No change
              Compare 6, 9. No change.

            Since there were no changes to the array, it is now in order from lowest to largest number.

<br>

## Part 2: printStars Functions

You will create a series of functions to fill vectors and diaplay stars. In these functions, every parameter will be [pass-by-reference](https://www.ibm.com/docs/en/zos/2.4.0?topic=calls-pass-by-reference-c-only).

1. In the `src` directory, create `printStars.h` and `printStars.cpp` files
  - the `.h` file must contain only the function declarations (prototypes).
  - the `.cpp` file must contain the implementation of the functions.
  - **Do not be using a class for this part**
  - Don't forget everything in C++ is case-sensitive. This includes file names.
2. Functions in `printStars`
  - `getNumberRange()`
    - Returns a  `size_t` entered from the keyboard. This is a positive number to set the range for the random integers generated. If the number equals 0, throw a const char* type of "The input does not meet the requirement".
  - `getNumberSize()`
    - Returns a  `size_t` entered from the keyboard. This size_t means how many numbers to generate(no more than 100). If the number doesn't meet the requirement, throw a const char* type of "The input does not meet the requirement".
  - `genRandomNumber(size_t&)`
    - Will receive a  `size_t` passed by reference, range. It will generate random number from 0 – range and return it as a `size_t`;
  - `scaleNumber(size_t&, size_t& )`
    - Will receive two  `size_t` passed by reference, generatedNumber and number. It will scale the generatedNumber to the desired range [-number, +number].
    This function will return an `int`.
    - If 0 is found after scaling, use genRandomNumber function to generate another number to replace it, until a non-zero number is generated.
  - `fillVector(vector<int>&, size_t&, size_t& )`
    - Will receive a `vector` of ints passed by reference, and
    two  `size_t` passed by reference, "numberRange" and "numberSize".
    - It will use genRandomNumber function to generate random number from 0 – numberRange. And then use the scaleNumber function to scales the generatedNumber to the desired range [-numberRange, +numberRange]. The scaled number is pushed onto the vector.
    - The number of "numberSize" will be pushed onto the vector. This function will not return anything


  - `printStars(vector<int>& )`
    - Will receive a `vector` of ints passed by reference.
    - prompt the user to enter a number assigned to index
    - It will print a single line of stars using data from the vector[index], 0 <= i <= vectorsize.  If number is positive, print vector[index] stars and vector[index]+1 blanks, shown as " * * * ".  If number is negative, print vector[index]+1 stars and vector[index] blanks, shown as "* * * *".
    - After display, reprompt the user to enter a number, until they enter 0 to quit.
    - Please do not output anything else except printStars.

<br>


3. Create a `main.cpp` file with an `int main()`and use it to test these methods. For error handling, use a try-catch block to catch and handle the error in your main.cpp. To test, create arrays of the correct length in main to pass as an argument for the part 1, and create vectors for part 2.

<!-- Important (Yellow) -->
<div
    style="background-color: #FEF9C3; border-left: 6px solid #F59E0B; color: #854D0E; padding: 16px;  border-radius: 5px;">
    <i class="fa-solid fa-exclamation" style="margin-right: 10px;"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Important!</b>
    <p>Failure to complete this step may result in a loss of points!</p>
</div>


## Testing

Your code will run against unit tests on an Autograder. The Autograder runs on Ubuntu Linux so the unit tests are configured for that OS only. You can run the tests in a Codespace (which uses Ubuntu as well) or on your own Ubuntu environment (if you have one) using the provided `g++` instructions. Remember tests must pass on the Autograder to receive points.

### Compiling

It is expected that you are able to compile and run your own code without relying solely on other tools. This includes the VS Code Debugger's "Play/Run" Button. You should not be using that at all for this assignment. Here is the general format for g++ (you leave out the `[]` characters when actually writing the commands ):

```bash
g++ [relevant setting and flags. These usually start with a '-'] [list of files to link together separated by a space : .cpp, .o, .a etc] -lpthread -o [name of the output file you wish to use]
```

The `g++` build command does use a couple extra settings when compiling with the unit tests. The additional options and what they signify are explained here:


- `[.cpp files, .o files, and .a files]` : Now, list off any .cpp source files, .o object files, and .a static library files that need to be included in the build. For all of these, you must include the relative file path for any files that aren't in your current working directory.
    - You will first list off any `.cpp` files needed by your program to run. In general, if your code uses an `#include "*.h"` statement, you will put the corresponding `.cpp` file here.
    - Then, add the object file for the test(s) you wish to run. Remember you must also include the relative file path if you are in a different working directory from the .o file (for example, `../tests/` if you are in the `src` folder or just `tests/` if you at the root of the repo).
    - Lastly, include the file `gtest_main.a`. This file contains the `main` program needed to launch the unit tests against your code.
        - Remember: A build must include **_exactly one (1)_** main function so you can't include your own main when running the unit tests.

- `-lpthread`: Links the pthread library to the resulting executable. In essence, it ensures that threading functions are available in the resulting binary. The unit tests use multithreading which is why we are including it.

- `-o` : This option lets you specify the name of the file you want `g++` to output the executable code. If a file with that name already exists, *it will be overwritten*. The default output file is `a.out` if you don't include this option.

Here is an example of a build command that could be used for this assignment. In this example, the working directory is `repository root` or top level of the repository:

```bash
g++ src/useArray.cpp tests/gtest_main.a tests/howMany_test.o -lpthread -o howMany_test.exe
```

Modify it as needed to run the tests as you wish. The autograder will also still run on each push to your repo if you prefer to test that way.

<div
    style="background-color: #FFFBEB; border-left: 6px solid #F97316; color: #813F0B; padding: 16px; border-radius: 5px;">
    <i class="fa-solid fa-triangle-exclamation" style="margin-right: 10px;"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Caution</b>
    <p>Do <b>not</b> attempt to force the unit tests to pass by hardcoding in responses to expected values. Attempts to bypass or "trick" the Autograder are considered academic misconduct and may result in a 0 for the whole assignment.</p>
</div>


## Rubric & Grading

Here is the breakdown of the tests, what they test, and how many points they are worth.

### useArray

| Test Name                  | Description                                       | points |
| -------------------------- | ------------------------------------------------- | ----: |
| howMany_test               | Verifies if `how many` return a number  that meet the requirements and include errorhandling    |     3 |
| fillArray_test             | Verifies if `fillArray` populates the array with a given number of random values     |     3 |
| printArray_test            | Verifies if `printArray` outputs the array in the proper format                      |     4 |
| dupeCheck_test             | Verifies  if `dupeCheck` could check if the Array Contains any Duplicates                  |     10 |
| sortArray_test             | Verifies if `sortArray` could arrange the elements of the array in ascending order.        |     10 |

### printStars

| Test Name                  | Description                                       | points |
| -------------------------- | ------------------------------------------------- | ----: |
| getNumberRange_test       | Verifies if `getNumberRange` return a number  that meet the requirements and include errorhandling |     3 |
| getNumberSize_test         | Verifies if `getNumberSize` return a number  that meet the requirements and include errorhandling |     3 |
| genRandomNumber_test       | Verifies if `genRandomNumber` return a random number that meet the requirements|     4 |
| scaleNumber_test           | Verifies if `scaleNumber` scales the number to the desired range|     10 |
| fillVector_test            | Verifies if `fillVector` fills the vector with random numbers generated |     10 |
| printStars_test            | Verifies if `printStars` prints a single line of stars using data from the vector[i] |     20 |


<div
    style="background-color: #E5F6FF; border-left: 6px solid #2CA5E0; color: #091E42; padding: 10px; border-radius: 5px;">
    <i class="fa-solid fa-circle-info"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Grading Breakdown & Style Points</b>
    <p>Assignments on Canvas will be recorded out of 100 points.</p>
    <p>The grading of homework is a combination of completeness and correctness of the outputs and programming style.
Completeness and correctness (80 points) will be assessed automatically through testing on GitHub Classroom,
while instructors and TAs will assess the programming style after the deadline (20 points).</p>
    <p>Code style will be evaluated using the guidelines shown in the Modules on Canvas.</p>
    <p>This grading will be done manually by the TAs after the deadline.</p>
</div>
<br>
<!-- Important (Yellow) -->
<div
    style="background-color: #FEF9C3; border-left: 6px solid #F59E0B; color: #854D0E; padding: 16px;  border-radius: 5px;">
    <i class="fa-solid fa-exclamation" style="margin-right: 10px;"></i>
    <b style="display: inline; margin-bottom: 8px; font-size: 16px;">Important Note Regarding the Rubric</b>
    <p>This Rubric is a breakdown of the test cases and their points only!</p>
    <p>You must also review the Rubric on the Canvas Assignment for the rest of the grading criteria.</p>
</div>
