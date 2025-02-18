#include<stdio.h>
#include<string.h>
void reverseString(char *str) {
    int len = strlen(str);
    for(int left = 0, right=len-1; left < right; left++, right--) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}

int main() {
    char str[255];
    printf("Enter a string:");
    scanf("%s", str);
    printf("Before reverse:%s\n");
    reverseString(str);
    printf("Reversed string:%s\n");
    return 0;
}