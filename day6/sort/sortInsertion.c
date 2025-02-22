#include<stdio.h>
int sortInsertion(float* salaries, int size);
void printSalaries(float* salaries, int size);
int main() {
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f};
    int salariiesCount = 5;
    printf("Before Sort:\n");printSalaries(salaries, salariiesCount);
    sortInsertion(salaries, salariiesCount);
    printf("After Sort:\n");printSalaries(salaries, salariiesCount);
    return 0;
}
void printSalaries(float* salaries, int size) {
    for(int I = 0; I < size; I++) {
        printf("%.2f ", salaries[I]);
    }
    printf("\n");
}
int sortInsertion(float* salaries, int size) {
    for(int I = 1; I < size; I++) {
        int targetIndex = I;
        float target = salaries[targetIndex];
        for(int sortedIndex = I -1; 
            sortedIndex >= 0 && salaries[sortedIndex] > target; 
            sortedIndex--) {
            salaries[targetIndex] = salaries[sortedIndex];
            targetIndex--;
        }
        if(targetIndex != I) {
            salaries[targetIndex] = target;
        }
    }
}

