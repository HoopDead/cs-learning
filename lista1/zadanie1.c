#include <stdio.h>

int isEven(int Number) {
    (Number % 2 == 0) ? printf("%d is even.", Number) : printf("%d is odd.", Number);
    return 0;
}

int main() {
    printf("Hello world!");
    isEven(2);
    return 0;
}