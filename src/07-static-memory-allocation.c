#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct employee_t {
	int id;
	int income;
	bool staff;
};

void init_employee(struct employee_t *e) {
	// static definitions are evaluated only once
	// Each time this function is called, the
	// value will be incremented
	static int employeeId = 0;
	employeeId++;

	e->id = employeeId;
	e->income = 0;
	e->staff = false;

	return;
}

int main() {
	int n = 5;
	struct employee_t *employees = malloc(sizeof(struct employee_t));

	if (employees == NULL) {
		printf("failed to allocate");

		return -1;
	}

	for (int i = 0; i < n; i++) {
		init_employee(&employees[i]);
		printf("%d\n", employees[i].id);
	}

	free(employees);
	employees = NULL;

	return 1;
}
