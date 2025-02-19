#include<stdio.h>
#define MAX_SUBJECTS 10
void calculateTotalMarks(int marks[][MAX_SUBJECTS], int studentsCount, int subjectsCount, int totalMarks[]) {
    for(int I = 0; I < studentsCount; I++) {
        totalMarks[I] = 0;
        for(int J = 0; J < subjectsCount; J++) {
            totalMarks[I] += marks[I][J];
        }
    }
}
void swap(int* first, int* second) {
    int temp = (*first);
    (*first) = (*second);
    (*second) = temp;
}
void sortStudents(int totalMarks[], int studentsCount) {
    int isSwapped = 0;
    
    do {
        isSwapped = 0;
        for(int I = 0; I < (studentsCount-1); I++) {
            if(totalMarks[I] < totalMarks[I+1]) {
                swap(&totalMarks[I], &totalMarks[I+1]);
                isSwapped = 1;
            }
        }
        studentsCount--;
    } while(isSwapped);

}
void readStudentMarks(int marks[][MAX_SUBJECTS], int studentsCount, int subjectsCount) {
    printf("Enter marks:");
    for(int I = 0; I < studentsCount; I++) {
        printf("Student %d:", I + 1);
        for(int J = 0; J < subjectsCount; J++) {
            scanf("%d", &marks[I][J]);
        }
    }
}
void printTotalMarks(int totalMarks[], int studentsCount) {
    for(int I = 0; I < studentsCount; I++) {
        printf("Total Marks: %d\n", totalMarks[I]);
    }
}
int main() {    
    int studentsCount;
    int subjectsCount;
    int marks[1000][MAX_SUBJECTS];
    int totalMarks[1000] = { };
    printf("Enter number of students:");
    scanf("%d", &studentsCount);
    printf("Enter number of subjects:");
    scanf("%d", &subjectsCount);
    readStudentMarks(marks, studentsCount, subjectsCount);
    calculateTotalMarks(marks, studentsCount, subjectsCount, totalMarks);
    sortStudents(totalMarks, studentsCount);
    printTotalMarks(totalMarks, studentsCount);
    return 0;
}

