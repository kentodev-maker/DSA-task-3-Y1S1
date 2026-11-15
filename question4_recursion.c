#include <stdio.h>

unsigned long long factorial(unsigned int number) {
    if (number == 0) {
        return 1;
    }
    return number * factorial(number - 1);
}

unsigned long long fibonacci(unsigned int number) {
    if (number <= 1) {
        return number;
    }
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int gcd(int first, int second) {
    if (second == 0) {
        return first < 0 ? -first : first;
    }
    return gcd(second, first % second);
}

int main(void) {
    unsigned int number;
    int first;
    int second;

    printf("Enter a non-negative integer: ");
    scanf("%u", &number);
    printf("Factorial: %llu\n", factorial(number));
    printf("Fibonacci: %llu\n", fibonacci(number));

    printf("Enter two integers for GCD: ");
    scanf("%d %d", &first, &second);
    printf("GCD: %d\n", gcd(first, second));

    return 0;
}
