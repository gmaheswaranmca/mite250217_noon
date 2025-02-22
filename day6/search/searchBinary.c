#include<stdio.h>
int searchBinary(float* salaries, int size, float searchSalary); //salaries - sorted
int main() {
    float salaries[] = {10.0f, 12.0f, 13.0f, 15.0f, 20.0f};
    int salariiesCount = 5;
    float searchSalary = 15.0f;
     int index = searchBinary(salaries, salariiesCount, searchSalary);
    printf("%.2f found at index %d\n", searchSalary, index);
    return 0;
}
int searchBinary(float* salaries, int size, float searchSalary) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(salaries[mid] == searchSalary) {
            return mid;
        } else if(searchSalary < salaries[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}