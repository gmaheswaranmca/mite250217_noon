#include<stdio.h>
int searchLinear(float* salaries, int size, float searchSalary);
int main() {
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f};
    int salariiesCount = 5;
    float searchSalary = 15.0f;
    int index = searchLinear(salaries, salariiesCount, searchSalary);
    printf("%.2f found at index %d\n", searchSalary, index);
    return 0;
}
int searchLinear(float* salaries, int size, float searchSalary) {
    for(int I = 0; I < size; I++) {
        if(salaries[I] == searchSalary) {
            return I;
        }
    }
    return -1;
}