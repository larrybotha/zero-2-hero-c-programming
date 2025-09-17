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

## Pointers & memory allocation

The word size boundary of the architecture determines the increments for virtual addresses.

e.g. if there is a 4 byte boundary, we may see the following addresses and allocations:

| virtual address | data    | note |
| ---             | ---     | ---  |
| 0x1000          | 0x0     |      |
| 0x1004          | 0x1234  | 4 bytes of data    |
| 0x1008          | 0x100C  | a reference to a memory afdress, i.e. a pointer    |
| 0x100C          | 0x0     |      |
| 0x1010          | 0x0     |      |
### 

The most important thing to know about the memory model when working in C is that:

- there are memory addresses
- there is data at those addresses

See these articles for clarification on virtual memory and memory mappings:

- https://sam4k.com/linternals-virtual-memory-part-1/
- https://sam4k.com/linternals-virtual-memory-0x02/

Hexadeciml can represent larger numbers in fewer characters than binary and decimal. Furthermore, a 2-digit hex value can represent a byte - i.e. an 8-bit binary value van be written as a 2 character hex value

- 0x0f => b00001111 => 128
- 0xff => b11111111 => 256

### Process memory map

The OS maps a process's virtual memory to physical memory

This map is roughly structured like this:

- text segment - contains executable code
- initialised data segment - global and static variables of the process
- uninitialised data segment - uninitialised global and static variables of the process
- heap - dynamically allocated memory
    - grows upward
    - affected by:
        - malloc
        - realloc
        - free
- stack - memory for function calls and scoped variables
    - grows downward
- memory-mapped regions - shared libraries and files in memory
    - lies between stack and heap

To evaluate a process's memory map, one can use `/proc/self/maps/ on Linux. e.g.

```shell
$ cat /proc/self/maps
```

Further reading: 

- https://en.wikipedia.org/wiki/Virtual_memory
- https://www.cprogramming.com/tutorial/c/lesson6.htmlz 
