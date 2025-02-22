#include<stdio.h>
int bubbleSort(float* salaries, int size);
void printSalaries(float* salaries, int size);
void swap(float* first, float* second);
int main() {
    float salaries[] = {20.0f, 10.0f, 15.0f, 12.0f, 13.0f};
    int salariiesCount = 5;
    printf("Before Sort:\n");printSalaries(salaries, salariiesCount);
    bubbleSort(salaries, salariiesCount);
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
int bubbleSort(float* salaries, int size) {
    int isSwapped;
    do {
        isSwapped = 0;
        for(int I = 0; I < (size-1); I++) { //pass
            if(salaries[I] > salaries[I+1]) {
                swap(&salaries[I], &salaries[I+1]);
                isSwapped = 1;
            }
        }
        size--;
    }while(isSwapped);
    
}

