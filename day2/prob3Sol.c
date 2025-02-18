#include<stdio.h>
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
    int marks[1000];
    printf("Number of students:");
    scanf("%d",&n);

    inputMarks(marks, n);
    float average = calculateAverage(marks, n);
    printf("Average marks:%.2f", average);
    return 0;
}