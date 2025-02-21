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
void displayEmployeesUsingStack(Employee emp[], int n);
Employee findHighestSalaried(Employee emp[], int n);
//
#define STACK_SIZE 1000
typedef Employee T;
typedef struct { 
    T elements[STACK_SIZE];
    int _size;
    int _top;
} Stack;
void StackInit(Stack* stk);
void StackPush(Stack* stk, T element);
int StackEmpty(Stack* stk);
T StackTop(Stack* stk);
void StaockPop(Stack* stk);

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
//
void StackInit(Stack* stk) {
    stk->_size = 0;
    stk->_top = -1;
}
void StackPush(Stack* stk, T element) {
    stk->elements[stk->_size] = element;
    stk->_size++;
    stk->_top++;
}
int StackEmpty(Stack* stk) {
    return (stk->_top == -1);
}
T StackTop(Stack* stk) {
    return stk->elements[stk->_top];
}
void StaockPop(Stack* stk) {
    if(StackEmpty(stk)) {
        printf("Stack is empty.\n");
        return;
    }
    stk->_top--;
    stk->_size--;
}
