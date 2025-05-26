#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265359

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

void basicCalculator() {
    int choice;
    double a, b, result;

    printf("\n-------------------------------------------\n");
    printf("        BASIC CALCULATOR\n");
    printf("-------------------------------------------\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Back to Main Menu\n");
    printf("-------------------------------------------\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        printf("Enter first number: ");
        scanf("%lf", &a);
        printf("Enter second number: ");
        scanf("%lf", &b);
    }

    printf("\n");

    FILE *fp = fopen("history.txt", "a");

    switch (choice) {
        case 1:
            result = a + b;
            printf("Result: %.2lf\n", result);
            if (fp) fprintf(fp, "Addition: %.2lf + %.2lf = %.2lf\n", a, b, result);
            break;
        case 2:
            result = a - b;
            printf("Result: %.2lf\n", result);
            if (fp) fprintf(fp, "Subtraction: %.2lf - %.2lf = %.2lf\n", a, b, result);
            break;
        case 3:
            result = a * b;
            printf("Result: %.2lf\n", result);
            if (fp) fprintf(fp, "Multiplication: %.2lf * %.2lf = %.2lf\n", a, b, result);
            break;
        case 4:
            if (b == 0)
                printf("Error: Division by zero!\n");
            else {
                result = a / b;
                printf("Result: %.2lf\n", result);
                if (fp) fprintf(fp, "Division: %.2lf / %.2lf = %.2lf\n", a, b, result);
            }
            break;
        case 5:
            if ((int)b == 0)
                printf("Error: Modulus by zero!\n");
            else {
                int mod = (int)a % (int)b;
                printf("Result: %d\n", mod);
                if (fp) fprintf(fp, "Modulus: %d %% %d = %d\n", (int)a, (int)b, mod);
            }
            break;
        case 6:
            if (fp) fclose(fp);
            return;
        default:
            printf("Invalid choice!\n");
            if (fp) fclose(fp);
            return;
    }

    if (fp) fclose(fp);

    printf("\nPress Enter to continue...\n");
    getchar(); getchar();
}

void scientificCalculator() {
    int choice, n;
    double x, y, result;
    FILE *fp;

    while (1) {
        printf("\n-------------------------------------------\n");
        printf("     SCIENTIFIC CALCULATOR\n");
        printf("-------------------------------------------\n");
        printf("1. Power (x^y)\n");
        printf("2. Square Root\n");
        printf("3. Factorial\n");
        printf("4. Trigonometry Calculations\n");  // grouped option
        printf("5. Logarithm (log10)\n");
        printf("6. Natural Log (ln)\n");
        printf("7. Exponential (e^x)\n");
        printf("8. Inverse (1/x)\n");
        printf("9. Back to Main Menu\n");
        printf("-------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");
        fp = fopen("history.txt", "a");

        switch (choice) {
            case 1:
                printf("Enter base (x): ");
                scanf("%lf", &x);
                printf("Enter power (y): ");
                scanf("%lf", &y);
                result = pow(x, y);
                printf("Result: %.4lf\n", result);
                if (fp) fprintf(fp, "Power: %.2lf ^ %.2lf = %.4lf\n", x, y, result);
                break;
            case 2:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x < 0) {
                    printf("Error: Cannot find square root of negative number!\n");
                    if (fp) fclose(fp);
                    return;
                }
                result = sqrt(x);
                printf("Result: %.4lf\n", result);
                if (fp) fprintf(fp, "Square Root of %.2lf = %.4lf\n", x, result);
                break;
            case 3:
                printf("Enter number: ");
                scanf("%d", &n);
                if (n < 0)
                    printf("Error: Factorial of negative number is undefined!\n");
                else {
                    int res = factorial(n);
                    printf("Result: %d\n", res);
                    if (fp) fprintf(fp, "Factorial: %d! = %d\n", n, res);
                }
                if (fp) fclose(fp);
                printf("\nPress Enter to continue...\n");
                getchar(); getchar();
                return;
            case 4: {
                int trigChoice;
                printf("\n--- Trigonometry Calculations ---\n");
                printf("1. Sine\n");
                printf("2. Cosine\n");
                printf("3. Tangent\n");
                printf("4. Back\n");
                printf("Enter your choice: ");
                scanf("%d", &trigChoice);

                switch (trigChoice) {
                    case 1:
                        printf("Enter angle in degrees: ");
                        scanf("%lf", &x);
                        result = sin(x * PI / 180);
                        printf("Result: %.4lf\n", result);
                        if (fp) fprintf(fp, "Sine of %.2lf degrees = %.4lf\n", x, result);
                        break;
                    case 2:
                        printf("Enter angle in degrees: ");
                        scanf("%lf", &x);
                        result = cos(x * PI / 180);
                        printf("Result: %.4lf\n", result);
                        if (fp) fprintf(fp, "Cosine of %.2lf degrees = %.4lf\n", x, result);
                        break;
                    case 3:
                        printf("Enter angle in degrees: ");
                        scanf("%lf", &x);
                        result = tan(x * PI / 180);
                        printf("Result: %.4lf\n", result);
                        if (fp) fprintf(fp, "Tangent of %.2lf degrees = %.4lf\n", x, result);
                        break;
                    case 4:
                        if (fp) fclose(fp);
                        continue;  // back to main scientific menu
                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;
            }
            case 5:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x <= 0) {
                    printf("Error: log10 is undefined for non-positive numbers!\n");
                    if (fp) fclose(fp);
                    return;
                }
                result = log10(x);
                printf("Result: %.4lf\n", result);
                if (fp) fprintf(fp, "Logarithm base 10 of %.2lf = %.4lf\n", x, result);
                break;
            case 6:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x <= 0) {
                    printf("Error: ln is undefined for non-positive numbers!\n");
                    if (fp) fclose(fp);
                    return;
                }
                result = log(x);
                printf("Result: %.4lf\n", result);
                if (fp) fprintf(fp, "Natural Log of %.2lf = %.4lf\n", x, result);
                break;
            case 7:
                printf("Enter exponent: ");
                scanf("%lf", &x);
                result = exp(x);
                printf("Result: %.4lf\n", result);
                if (fp) fprintf(fp, "Exponential (e^%.2lf) = %.4lf\n", x, result);
                break;
            case 8:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x == 0) {
                    printf("Error: Division by zero!\n");
                    if (fp) fclose(fp);
                    return;
                }
                result = 1 / x;
                printf("Result: %.4lf\n", result);
                if (fp) fprintf(fp, "Inverse of %.2lf = %.4lf\n", x, result);
                break;
            case 9:
                if (fp) fclose(fp);
                return;
            default:
                printf("Invalid choice!\n");
        }

        if (fp) fclose(fp);
        printf("\nPress Enter to continue...\n");
        getchar(); getchar();
    }
}


void showHistory() {
    FILE *fp = fopen("history.txt", "r");
    char ch;

    printf("\n-------------------------------------------\n");
    printf("             CALCULATION HISTORY\n");
    printf("-------------------------------------------\n");

    if (fp == NULL) {
        printf("No history found.\n");
    } else {
        while ((ch = fgetc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }

    printf("-------------------------------------------\n");
    printf("\nPress Enter to continue...\n");
    getchar(); getchar();
}
