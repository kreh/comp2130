#include <stdio.h>

int main() {
    int a, b, c;


    printf("Sort program | Dave Aldrich\n\nEnter three values of integers:");
    scanf("%d %d %d", &a, &b, &c);

    if ((a > b && a > c) && (b > c))
        printf("Low: %d\nMedium: %d\nHigh: %d\n", c, b, a);
    else if  ((a < b && a > c) && (b > c))
        printf("Low: %d\nMedium: %d\nHigh: %d\n", c, a, b);
    else if  ((c > a && c > b) && (a > b))
        printf("Low: %d\nMedium: %d\nHigh: %d\n", b, a, c);
    else if  ((a < b && a < c) && (b > c))
        printf("Low: %d\nMedium: %d\nHigh: %d\n", a, c, b);
    else if  ((a > b && a > c) && (b < c))
        printf("Low: %d\nMedium: %d\nHigh: %d\n", b, c, a);
    else if ((a < b && a < c) && (b > c))
        printf("Low: %d\nMedium: %d\nHigh: %d\n", a, b, c);
    else
        puts("All the same!");
    return 0;
}