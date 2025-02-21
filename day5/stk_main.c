#include<stdio.h>
#define STACK_SIZE 1000
typedef float T;
typedef struct { 
    T elements[STACK_SIZE];
    int _size;
    int _top;
} Stack;
void StackInit(Stack* stk);
void StackPush(Stack* stk, T element);
int StackEmpty(Stack* stk);
T StackTop(Stack* stk);
void StaockPop(Stack* stk);
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

void StackInit(Stack* stk) {
    stk->_size = 0;
    stk->_top = -1;
}
void StackPush(Stack* stk, T element) {
    stk->elements[stk->_size] = element;
    stk->_size++;
    stk->_top++;
}
int StackEmpty(Stack* stk) {
    return (stk->_top == -1);
}
T StackTop(Stack* stk) {
    return stk->elements[stk->_top];
}
void StaockPop(Stack* stk) {
    if(StackEmpty(stk)) {
        printf("Stack is empty.\n");
        return;
    }
    stk->_top--;
    stk->_size--;
}























