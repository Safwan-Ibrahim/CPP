#include <stdio.h>

void count_factors(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    printf("%d has %d factors.\n", num, count);
}

void sum_of_numbers(int num) {
    int sum = (num * (num + 1)) / 2;
    printf("Sum of first %d natural numbers is %d.\n", num, sum);
}

void reverse_number(int num) {
    int reversed = 0, remainder, original = num;
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    printf("Reverse of %d is %d.\n", original, reversed);
}

void check_century_year(int year) {
    if (year % 100 == 0) {
        printf("%d is a century year.\n", year);
    } else {
        printf("%d is not a century year.\n", year);
    }
}

void check_positive_negative(int num) {
    if (num >= 0) {
        printf("%d is a positive number.\n", num);
    } else {
        printf("%d is a negative number.\n", num);
    }
}

void check_even_odd(int num) {
    if (num & 1) {
        printf("%d is an odd number.\n", num);
    } else {
        printf("%d is an even number.\n", num);
    }
}

int main() {
    int choice, num, year, n;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Count Factors\n");
        printf("2. Sum of Natural Numbers\n");
        printf("3. Reverse a Number\n");
        printf("4. Century Year Check\n");
        printf("5. Positive or Negative\n");
        printf("6. Even or Odd\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                count_factors(num);
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);
                sum_of_numbers(num);
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &num);
                reverse_number(num);
                break;
            case 4:
                printf("Enter a year: ");
                scanf("%d", &year);
                check_century_year(year);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%d", &num);
                check_positive_negative(num);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%d", &num);
                check_even_odd(num);
                break;
            case 7:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
