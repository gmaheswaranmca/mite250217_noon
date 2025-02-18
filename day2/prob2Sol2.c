#include<stdio.h>
int findLength(char* str) {
    int length = 0;
    for(char* p_ch = str; (*p_ch) != '\0'; p_ch++) {
        length++;
    }
    return length;
}
void reverseString(char *str) {
    int len = findLength(str);
    for(int left = 0, right=len-1; left < right; left++, right--) {
        //swap char at left and char at right
        char temp = *(str +left); // *(str +left) == str[left]
        *(str+left) = *(str+right);
        *(str+right) = temp;
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