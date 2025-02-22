#include<stdio.h>
int sortInsertion(float* salaries, int size);
void printSalaries(float* salaries, int size);
void swap(float* first, float* second);
int main() {
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f};
    int salariiesCount = 5;
    printf("Before Sort:\n");printSalaries(salaries, salariiesCount);
    sortSelection(salaries, salariiesCount);
    printf("After Sort:\n");printSalaries(salaries, salariiesCount);
    return 0;
}
void printSalaries(float* salaries, int size) {
    for(int I = 0; I < size; I++) {
        printf("%.2f ", salaries[I]);
    }
    printf("\n");
}
void swap(float* first, float* second) {
    float temp = (*first);
    (*first) = (*second);
    (*second) = temp;
}
int sortSelection(float* salaries, int size) {
    for(int I = 0; I < (size-1); I++) { //selection 
        int minIndex = I;
        for(int J = I + 1; J < size; J++) { //pass : to find min index
            if(salaries[J] < salaries[minIndex]) {
                minIndex = J;
            }
        }
        if(I != minIndex) {
            swap(&salaries[I], &salaries[minIndex]);
        }
    }
}

