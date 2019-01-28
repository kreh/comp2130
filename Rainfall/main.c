/****
 * Name: Dave Aldrich
 * Student Number: T00593238
 * Seminar Number: 02
 * Due Date:  January 29, 2019
 * Program Description:  Assignment #2: Rainfall program with functions
 ****/

#include <stdio.h>
#include <math.h>
#include <mem.h>
#include <stdbool.h>
#include <malloc.h>
#include "rainfall_header.h"

bool flag;
char months[6][9] = {"January", "February", "March", "April", "May",
                     "June"}; // [6] is months len, [9] is for max allowed char alloc
double arrLastYear[6] = {3.1, 4.7, 4.2, 5.0, 4.0, 6.3};
double arrCurrentYear[6] = {5.4, 4.4, 4.1, 3.0, 5.6, 4.5};
double totalLastRainfall, totalCurrentRainfall, highestCurrentRainfall, lowestCurrentRainfall, delta, highestRainfall;
int iPtr;
int *ptr = &iPtr;
int hiPtr;

void arrayCheck() {
    double *table[2];
    double *x = table[0] = (double *) &arrLastYear;
    double *y = table[1] = (double *) &arrCurrentYear;
    flag = (*ptr == *x) ? true : false; // true = using last year; false = using current year
}

void *displayYc(int fromAdapt) {
    int length = (fromAdapt + 1);
    char token = getSymbol(iPtr);
    char *space = malloc(length);
    return memset(space, token, length);
}

char getSymbol() {
    char sender;
    if (flag == true)
        sender = '\x2A';
    else
        sender = '\x21';
    return sender;
}

double calcTotal(double A, double *B) {
    double final;

    for (int i = 0; i < 6; i++) {
        double x = final += B[i];
        if ((A = totalLastRainfall) && (B = arrCurrentYear) && (i < 6)) { // Total current rainfall
            x;
        } else if ((A = totalCurrentRainfall) && (B = arrLastYear) && (i < 6)) { // Total rainfall for 2018
            x;
        }
    }
    return final;
}

// Current vs New delta calculation
double calcDelta(double A) {
    double hi, lo, diff, temp;
    double *B = arrCurrentYear, *C = arrLastYear;

    // Just in case if B and C are flipped around
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            lo = B[i];
        } else if (i == 1) {
            hi = C[i];
        }
        while ((i < 6) && (i > 1)) { // bubble sort with hiPtr
            if (lo > hi) {
                temp = lo;
                lo = hi;
                hi = temp;
            }
        }
        diff = (hi - lo);
        hiPtr = hi;
        return diff;
}

int adapt(double E) {
    double i = ceil(E / 40 * 100);
    int o = i;
    return o;
}

void run() {
    char *lyd;
    char *cyd;
    delta = calcDelta(delta, arrLastYear, arrCurrentYear);

    puts("");
    for (int i = 0; i < 6; i++) {
        printf("%.1f %7.1f %7s %s %s", arrLastYear[i], arrCurrentYear[i], "* ", months[i], "data\n");
    }
    puts("\nRainfall comparison for January to June 2018\n");
    for (int iPtr = 0; iPtr < 6; iPtr++) {
        lyd = displayYc(adapt(arrLastYear[iPtr]));
        cyd = displayYc(adapt(arrCurrentYear[iPtr]));
        printf("%-8s %8s%s\n %16s%s\n %16s%s\n", months[iPtr], "|", lyd, "|", cyd, "|",
               ""); // displayYc = display Y co-ordinates
        if (iPtr == 5)
            printf("%-8s %8s%s\n %16s%s\n %16s%s\n", months[iPtr], "|", lyd, "|", cyd, "|", SCALE);
    }

    puts(LEGEND);

    printf("Total normal rainfall was %.1f mm.\n\nTotal rainfall for 2018 was %.1f mm.\n\n",
           calcTotal(totalLastRainfall, arrLastYear),
           calcTotal(totalCurrentRainfall, arrCurrentYear));
    printf("2018 was a drier year than normal by %.1f mm.", delta);

    printf("\n\nThe month with the highest rainfall was %s", months[hiPtr]);
}

int main() {
    run();
    return 0;
}













