#define STACK_SIZE 1000

#ifndef STACK_HEADER 
#define STACK_HEADER
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
#endif