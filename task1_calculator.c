#include <stdio.h>

int main() {
    double a, b;
    int choice;

    scanf("%lf %lf", &a, &b);
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%lf", a + b);
            break;
        case 2:
            printf("%lf", a - b);
            break;
        case 3:
            printf("%lf", a * b);
            break;
        case 4:
            if (b != 0)
                printf("%lf", a / b);
            else
                printf("Division by zero");
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}
