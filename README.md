e zero-2-hero-c-programming

Learnings from https://lowlevel.academy/courses/zero2hero

## Goal

To understand computers better. Understanding C should make it easier to understand what languages I'm proficient in are doing, and should assist in picking up other languages with concepts that arw foreign to the languages I'm familiar with.

## Setup

It seems that one should use `clang` in Termux for compilation

```shell
$ clang file.c -o my-file
```

## Course

### C Fundamentals

4 stages to compile a C program:

1. preprocessing - handling of all `#` directives
    `gcc -E` to only preprocess code
2. compilation - translation of code into assembly
    `gcc -S` to only translate into assembly - `.s` files
3. assembly - conversion of assembly into machine code
    `gcc -c` - compile to object files - `.o`
4. linking - connecting of all object files and libraries into a single executable
    `gcc` - full compilation

#### Preprocessing

In this stage directives in files are processed to augment the content of those files:

- `#include` injects the contents of included files into your files
- `#define, #undef` macro definitions replaces all occurrences of the definition with the defined value
- `#if, #elif, #else, #endif` - conditionally compilation to include or exclude code
- `#ifdef, #ifndef` - evaluation of defined macros
- `#pragma` - compiler-specific instructions
- `#line` - something something line something
- #warning, #error` - produces compile time errors and warnings

The result is still C code, which can be evaluated by compiling with `gcc -E`
