#include<stdio.h>
#include<stdlib.h>
void inputMarks(int *marks, int n) {
    printf("Enter marks:");
    for(int I = 0; I < n; I++) {
        scanf("%d", &marks[I]);
    }
}

float calculateAverage(int *marks, int n) {
    int sum = 0;
    for(int I = 0; I < n; I++) {
        sum += marks[I];
    }
    float average = (float)sum / (float)n;
    return average;
}

int main() {
    int n;
    printf("Number of students:");
    scanf("%d",&n);

    int* marks = (int*)malloc(sizeof(int) * n);//int marks[1000];
    

    inputMarks(marks, n);
    float average = calculateAverage(marks, n);
    printf("Average marks:%.2f", average);

    free(marks);
    return 0;
}