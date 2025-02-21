#include<stdio.h>
#include "stack.h"

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