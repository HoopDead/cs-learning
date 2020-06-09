#include <stdio.h>

int isDivisble(int number, int divisor) {
    if (number % divisor == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("%d", isDivisble(9, 3));
    return 0;
}