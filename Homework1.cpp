#include <iostream>
#include <math.h>
bool prime(long n) {
    long i, g;
    if (n % 2 == 0) {
        return 0;
    }
    for (i = 3; i <= ceil(sqrt(n)); i+=2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    long n, i;
    printf("Unesite broj, idealno prost:");
    scanf_s("%ld", &n);
    if (prime(n)) {
        for (i = 2; i < n; i++) {
            if (prime(i)) {
                printf("%ld ", i);
            }
        }
        printf("%ld", n);
    } else {
        printf("%ld nije prost.", n);
    }
    return 0;
}