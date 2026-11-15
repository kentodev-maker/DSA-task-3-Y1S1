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
#include <stdio.h>

unsigned long long factorial(unsigned int number) {
    if (number <= 1) return 1;
    return number * factorial(number - 1);
}

unsigned long long fibonacci(unsigned int number) {
    if (number <= 1) return number;
    return fibonacci(number - 1) + fibonacci(number - 2);
}

unsigned int gcd(unsigned int first, unsigned int second) {
    if (second == 0) return first;
    return gcd(second, first % second);
}

void print_reverse(unsigned int number) {
    printf("%u", number % 10);
    if (number >= 10) print_reverse(number / 10);
}

int main(void) {
    unsigned int number;
    unsigned int first;
    unsigned int second;

    printf("Enter a non-negative integer: ");
    scanf("%u", &number);
    printf("Factorial: %llu\n", factorial(number));
    printf("Fibonacci: %llu\n", fibonacci(number));
    printf("Digits in reverse: ");
    print_reverse(number);
    printf("\n\nEnter two non-negative integers for GCD: ");
    scanf("%u %u", &first, &second);
    printf("GCD: %u\n", gcd(first, second));
    return 0;
}
