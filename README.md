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

### Arrays and strings

- arrays represent a fixed allocation of contiguous space in memory for values of the same type
- a string is a array of type char

e.g. the following are equivalent:

```c
char xs[] = {'h', 'e', 'l'. 'l', 'o', 0};
char *x = "hello";
``

strings are terminated by a null byte (`\0`). This indicates where a string ends, otherwise a program may continue reading memory beyond what is allocated for the string.

`strcopy`, for instance, only stops copying when it hits a null byte.

Defining a string using the deref operator, as opposednto as a string, automatically appends the terminating null byte

### Structs and unions

Don't initialise a struct without values - doing this may assign it a location in
memory where the members are assigned the values at that location

```c
struct mystruct {
    int x;
    char c;
}

int main() {
    struct mystruct; // DO NOT DO THIS
}
```

A safer approach is to set values to zero:

```c
struct mystruct {
    int x;
    char c;
}

int main() {
    struct mystruct = {0}; // sets all values to zero
}
```

The ideal approach is to properly initialise the struct:

```c
struct mystruct {
    int x;
    char c;
}

int main() {
    struct mystruct = {
        .i = 42,
        .c = 'A',
    };
}
```

Members of structs that are arrays but do not have a fixed size need to be
defined after other members in the struct.

#### Unions

[./src/06-union.c](./src/06-union.c)

Unions are similar to structs, but are only allocated enough memory for the
largest type in the union. The other members of the union can still be accessed,
but will only return a portion of the value as per the memory allocated for
their type:

```c
union myunion {
    int i; // 32b
    char c; // 8b
}
```

This is useful in embedded systems where instead of having to perform a
calculation on `i` to get the first byte, one could instead evaluate `c`,
which will return the first byte because of how much memory is allocated to
that value




