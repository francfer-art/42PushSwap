<a href="https://github.com/francfer-art/42PushSwap">
  <img src ="https://raw.githubusercontent.com/15Galan/42_project-readmes/master/banners/cursus/projects/push_swap-dark.png")>
</a>

<p align="center">
  <a href="https://github.com/francfer-art/42PushSwap">
  <img src="https://raw.githubusercontent.com/mcombeau/mcombeau/main/42_badges/push_swapm.png" alt="PushSwap Logo">
  </a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-Evaluating-brightgreen" alt="PushSwap Score">
</p>

## Table of Contents

- [Introduction](#introduction)
- [Rules](#rules)
- [Example](#Example)
- [Usage](#Usage)
- [Requirements](#requirements)
- [Usage](#usage)
- [Avaliable Parameters](#avaliable-parameters)
- [Bonus](#bonus)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This repository contains a program named push_swap that sorts a stack named a in ascending order using a specific set of operations. Here are the rules and requirements for the program:

## Rules

```
The program operates on two stacks named a and b.
At the beginning:
Stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
Stack b is empty.
The goal is to sort numbers in stack a in ascending order.
Operations available:
sa: Swap the first 2 elements at the top of stack a.
sb: Swap the first 2 elements at the top of stack b.
ss: sa and sb at the same time.
pa: Take the first element at the top of b and put it at the top of a.
pb: Take the first element at the top of a and put it at the top of b.
ra: Rotate all elements of stack a by 1.
rb: Rotate all elements of stack b by 1.
rr: ra and rb at the same time.
rra: Reverse rotate all elements of stack a by 1.
rrb: Reverse rotate all elements of stack b by 1.
rrr: rra and rrb at the same time.
```

## Example

An example is provided to illustrate the effect of some instructions in sorting a random list of integers.

```c
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```

## Requirements

You must provide a Makefile which compiles the source files without relinking.
Global variables are forbidden.
Write a program named push_swap that takes the stack a as input formatted as a list of integers.
The program must display the smallest list of instructions possible to sort the stack a, with the smallest number being at the top.
Instructions must be separated by a newline character.
The goal is to sort the stack with the lowest possible number of operations. Your program will be evaluated based on the number of instructions and their correctness.
If no parameters are specified, the program must not display anything and return the prompt.
In case of errors (e.g., non-integer arguments, duplicates, integers exceeding the limit), it must display "Error" followed by a newline on the standard error.

## Usage

To use the push_swap program, compile the source files using the provided Makefile. Then run the program with the stack a as an argument.

```bash
./push_swap 4 2 8 5 1
```

This will display the smallest list of instructions to sort the stack a.
Thank you for using push_swap!

## Bonus Part

In addition to the core functionality, there's a bonus part which involves creating a custom checker:

```
Write a program named checker to validate sorting based on given instructions.
Follows specific rules for input, instructions, and error handling.
Outputs "OK" if the stack is sorted and "KO" otherwise.
Provides detailed error messages for incorrect input or instructions.
Thank you for using push_swap and checker! Feel free to explore and utilize these programs for sorting and validation tasks.
```

## Contributing 

Contributions are welcome! If you have improvements or additional features to suggest, please open an issue or submit a pull request. Follow the Contribution Guidelines for more details.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

