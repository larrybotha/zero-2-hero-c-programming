#include <stdio.h>

union myunion_u {
  int i;   // 4B or 32b
  char c;  // 1B or 8b
  short s; // 2B or 16b
};

int main() {
  union myunion_u u;
  u.i = 0x41424344;

  printf("%hx %hhx %c\n",
         u.s, // print the first 2 bytes
         u.c, // print the first byte
         u.c  // print the first byte
  );
}
