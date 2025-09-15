#include <stdbool.h>
#include <stdio.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
  int id;
  char firstname[64];
  char lastname[64];
  float income;
  bool ismanager;
};

int main() {
  struct employee_t employees[(int)MAX_EMPLOYEES];

  int i = 0;

  for (i = 0; i < MAX_EMPLOYEES; i++) {
    employees[i].income = 0;
    employees[i].ismanager = false;
  }

  printf("%f\n", employees[9].income);
}
