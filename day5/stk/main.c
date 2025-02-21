#include<stdio.h>
#include "stack.h"
int main() {    
    float salaries[] = {50000, 40000, 48000, 23000, 2000};
    Stack stk;
    StackInit(&stk);
    for(int I = 0; I < 5; I++) {
        StackPush(&stk, salaries[I]);
    }
    printf("Salaries from stack:\n");
    while(!StackEmpty(&stk)) {
        float sal = StackTop(&stk);
        printf("%.2f ", sal);
        StaockPop(&stk);
    }
    return 0;
}
























