#include<stdio.h>
#define MAX_SIZE 1000
struct Fiction_t { //508
    char title[250];
    char author[250];
    float price;
};
typedef struct Fiction_t Fiction;
struct NonFiction_t { //308
    char title[250];
    char subject[50];
    float price;
};
typedef struct NonFiction_t NonFiction;
union BookType_t {
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union BookType_t BookType;
struct Book_t {             //4 + 508 = 512
    int type;           
    BookType bookType;
};
typedef struct Book_t Book;

int bookCount;
Book books[MAX_SIZE];

void readBooks() {
    printf("Enter number of books:");
    scanf("%d", &bookCount);

    for(int I = 0; I < bookCount; I++) {
        printf("Enter book type(1-Fiction, 2-Non-fiction):");
        scanf("%d", &books[I].type);
        switch(books[I].type) { 
            case 1: {
                printf("Enter Fiction Book Details (title, author, price):");
                scanf("%s%s%f",books[I].bookType.fiction.title, 
                             books[I].bookType.fiction.author,
                             &books[I].bookType.fiction.price);
            } break;
            case 2: {
                printf("Enter Non-Fiction Book Details (title, subject, price):");
                scanf("%s%s%f",books[I].bookType.nonFiction.title, 
                             books[I].bookType.nonFiction.subject,
                             &books[I].bookType.nonFiction.price);
            } break;
        }
    }
}

void displayBooks() {
    for(int I = 0; I < bookCount; I++) {
        switch(books[I].type) { 
            case 1: {
                printf("Fiction Book: %s,%s,%.2f\n",books[I].bookType.fiction.title, 
                             books[I].bookType.fiction.author,
                             books[I].bookType.fiction.price);
            } break;
            case 2: {
                printf("Non-Fiction Book:%s,%s,%f\n",books[I].bookType.nonFiction.title, 
                             books[I].bookType.nonFiction.subject,
                             books[I].bookType.nonFiction.price);
            } break;
        }
    }
}

int main() {
    readBooks();
    displayBooks();
    return 0;
}