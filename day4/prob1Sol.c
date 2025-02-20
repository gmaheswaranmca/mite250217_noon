#include<stdio.h>
struct Employee_t {
    int id;
    char name[250];
    float salary;
    char department[50];
};

typedef struct Employee_t  Employee;

void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalaried(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter number of employees:");
    scanf("%d", &employeeCount);

    Employee employees[1000];
    readEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    Employee highestSalaried = findHighestSalaried(employees, employeeCount);
    printf("Employee with highest salary: %s, %.2f (%s)\n", highestSalaried.name, 
        highestSalaried.salary, highestSalaried.department);
    return 0;
}

void readEmployees(Employee emp[], int n) {
    printf("Enter details (ID, Name, Salary, Department):");
    for(int I = 0; I < n; I++) {
        scanf("%d%s%f%s", &emp[I].id, emp[I].name, 
                &emp[I].salary, emp[I].department);
    }
}
void displayEmployees(Employee emp[], int n) {
    printf("Employees:\n");
    for(int I = 0; I < n; I++) {
        printf("%d - %s - %.2f - %s\n", emp[I].id, emp[I].name, 
            emp[I].salary, emp[I].department);
    }
}
Employee findHighestSalaried(Employee emp[], int n) {
    Employee maxEmployee = emp[0];
    for(int I = 1; I < n; I++) {
        if(emp[I].salary > maxEmployee.salary) {
            maxEmployee = emp[I];
        }
    }
    return maxEmployee;
}