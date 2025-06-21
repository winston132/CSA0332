#include <stdio.h>

typedef struct {
    int data;
} ADT;

void setData(ADT *adt, int value) {
    adt->data = value;
}

int getData(ADT *adt) {
    return adt->data;
}

int main() {
    ADT myADT;
    setData(&myADT, 10);
    printf("Data: %d\n", getData(&myADT));
    return 0;
}

