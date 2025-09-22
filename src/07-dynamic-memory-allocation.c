#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  int income;
  bool staff;
};

void initialize_employee(struct employee_t *e) {
  e->id = 0;
  e->income = 0;
  e->staff = false;

  return;
}

int main() {
  /*
   * naive approach
   *
   * - use a compile-time value to determine how much memory to allocate
   * - initialise an array of 1000 employees on the stack
   *    - This is 1000 * (int + int + bool) - a big waste of memory
   */
  /*struct employee_t employees[MAX_EMPLOYEES];*/
  /*
   * better approach:
   *
   * - use malloc to allow for
   * - use malloc to allow for
   */
  int n = 4; // some runtime value, e.g. limit for DB selects

  struct employee_t *employees = malloc(sizeof(struct employee_t) * n);

  // always check if malloc succeeded - it's not guaranteed to succeed
  if (employees == NULL) {
    printf("The allocator failed");

    return -1;
  }

  initialize_employee(&employees[0]);

  printf("%d\n", employees[0].income);

  free(employees); // free the memory we allocated using malloc
  // Set the pointer to NULL - this prevents dangling pointers, and
  // 'use-after-free' errors
  // Once this is set to NULL, the application will crash if attempting to
  // use this value
  employees = NULL;
}
