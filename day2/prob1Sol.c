#include<stdio.h>
float calculateBill(char wardType, int days) {
    float amount;
    float price;
    switch(wardType) {
        case 'G': {
            price = 1000.0f;
        } break;
        case 'S': {
            price = 2000.0f;
        } break;
        case 'P': {
            price = 5000.0f;
        } break;
    }
    amount = price * days;
    if(days > 7) {
        amount = amount * 0.95f;
    }
    return amount;
}

int main() {
    // input name, wardType, daysAdmitted
    char name[255];
    char wardType;
    int daysAdmitted;

    printf("Enter Patient Name:");
    scanf("%s", name); getchar();

    printf("Enter Ward Type (G:General/S:Semi-Private/P:Private):");
    scanf("%c", &wardType);

    printf("Enter Number of Days:");
    scanf("%d", &daysAdmitted);

    float amount = calculateBill(wardType, daysAdmitted);

    printf("Patient Name: %s", name);
    printf("Bill Amount: %.2f", amount);
    return 0;
}