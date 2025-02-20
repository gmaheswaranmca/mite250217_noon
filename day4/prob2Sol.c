#include<stdio.h>
struct Employee_t {
    int id;
    char name[250];
    float salary;
    char department[50];
};

typedef struct Employee_t  Employee;

void readEmployees(Employee emp[], int n);
void saveEmployees(Employee emp[], int n);
void loadEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalaried(Employee emp[], int n);

int main() {
    int employeeCount;
    printf("Enter number of employees:");
    scanf("%d", &employeeCount);

    Employee employees[1000];
    readEmployees(employees, employeeCount);
    saveEmployees(employees, employeeCount);
    loadEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    Employee highestSalaried = findHighestSalaried(employees, employeeCount);
    printf("Employee with highest salary: %s, %.2f (%s)\n", highestSalaried.name, 
        highestSalaried.salary, highestSalaried.department);
    return 0;
}

void readEmployees(Employee emp[], int n) {
    printf("Enter details (ID, Name, Salary, Department):\n");
    for(int I = 0; I < n; I++) {
        scanf("%d%s%f%s", &emp[I].id, emp[I].name, 
                &emp[I].salary, emp[I].department);
    }
}
void saveEmployees(Employee emp[], int n) {
    FILE* file = fopen("employees.txt", "w");
    //
    if(file == NULL) {
        printf("Error in creating file.\n");
        return;
    }
    //
    for(int I = 0; I < n; I++) {
        fprintf(file, "%d %s %.2f %s\n", emp[I].id, emp[I].name, 
            emp[I].salary, emp[I].department);
    }
    //
    fclose(file);
}
void loadEmployees(Employee emp[], int n) {
    FILE* file = fopen("employees.txt", "r");
    //
    if(file == NULL) {
        printf("Error in reading file.\n");
        return;
    }
    //
    for(int I = 0; I < n; I++) {
        fscanf(file, "%d %s %f %s\n", &emp[I].id, emp[I].name, 
            &emp[I].salary, emp[I].department);
    }
    //
    fclose(file);
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