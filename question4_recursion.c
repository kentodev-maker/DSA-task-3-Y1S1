#include <stdio.h>

unsigned long long sum_natural_numbers(unsigned int number) {
    if (number == 0) return 0;
    return number + sum_natural_numbers(number - 1);
}

unsigned long long factorial(unsigned int number) {
    if (number <= 1) return 1;
    return number * factorial(number - 1);
}

unsigned long long fibonacci_term(unsigned int number) {
    if (number <= 1) return number;
    return fibonacci_term(number - 1) + fibonacci_term(number - 2);
}

void print_fibonacci_terms(unsigned int number, unsigned int current,
                           unsigned long long first,
                           unsigned long long second) {
    if (current == number) return;
    printf("%llu ", first);
    print_fibonacci_terms(number, current + 1, second, first + second);
}

int main(void) {
    unsigned int number;

    printf("Enter N: ");
    scanf("%u", &number);

    printf("Sum of first N natural numbers: %llu\n",
           sum_natural_numbers(number));
    printf("Factorial: %llu\n", factorial(number));
    printf("Nth Fibonacci term: %llu\n", fibonacci_term(number));
    printf("First N Fibonacci terms: ");
    print_fibonacci_terms(number, 0, 0, 1);
    printf("\n");

    return 0;
}
