#include<stdio.h>
#include<stdlib.h>
typedef float T;
struct Node_t{
    T element;
    struct Node_t* next;
    struct Node_t* prev;
};
typedef struct Node_t Node; 

typedef struct { 
    Node *head;
    Node *tail;
    int _size;
} List;

void ListInit(List* list);
Node* CreateNode(T element);
void ListPushFront(List* list, T element);
void ListPushBack(List* list, T element);
int ListEmpty(List* list);
T ListFront(List* list);
T ListBack(List* list);
void ListPopFront(List* list);
void ListPopBack(List* list);

int main() {
    float salaries[] = {50000, 40000, 48000, 23000, 2000};
    List list;
    ListInit(&list);
    for(int I = 0; I < 5; I++) {
        ListPushBack(&list, salaries[I]);
    }

    printf("Salaries:\n");//forward traversal
    for(Node* node = list.head; node != NULL; node = node->next) {
        printf("%.2f ", node->element);
    }
    return 0;
}

void ListInit(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->_size = 0;
}
Node* CreateNode(T element) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->element = element;
    node->prev = NULL;
    node->next = NULL;
}
void ListPushFront(List* list, T element) {

}
void ListPushBack(List* list, T element) { // x x
    Node* node = CreateNode(element);      // x50000x
    if(list->head == NULL) {               // x50000->  <-40000x 
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}
int ListEmpty(List* list) {

}
T ListFront(List* list) {

}
T ListBack(List* list) {

}
void ListPopFront(List* list) {

}
void ListPopBack(List* list) {
    
}