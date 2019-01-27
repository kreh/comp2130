/****
 * Name: Dave Aldrich
 * Student Number: T00593238
 * Seminar Number: 02
 * Due Date:  January 29, 2019
 * Program Description:  Assignment #2: Rainfall program with functions
 ****/

#include <stdio.h>
#include <math.h>

#pragma clang diagnostic push
#pragma clang diagnostic pop
#pragma clang diagnostic ignored "-Wformat"
#pragma clang diagnostic ignored "-Wunused-value"
#pragma clang diagnostic ignored "-Wint-conversion"

// [6] is months len, [9] is for max allowed char alloc
char months[6][9] = {"January", "February", "March", "April", "May", "June"};
double tCurRainfall, tNewRainfall, hNewRainfall, lNewRainfall, delta, highest;
double arrCur[6] = {3.1, 4.7, 4.2, 5.0, 4.0, 6.3};
double arrNew[6] = {5.4, 4.4, 4.1, 3.0, 5.6, 4.5};
int iPtr = INIT;

char displayYc(int adapter) {
    char *token = token;
    token = getSymbol(iPtr);

    for (int xNumRep = 0; xNumRep <= adapter; xNumRep++) {
        char *temp = token;
        token = *temp;
    }
    return token;
}

char getSymbol(int index) {
    char sender;
    if (index = arrCur[index])
        sender = '*';
    else
        sender = '!';
    return sender;
}

double calcHiLo(double E, double *A) {
    double hi, delta;
    double final;


    for (int i = 0; i < 6; i++) {
        double x = (final += A[i]);
        if ((E = tCurRainfall) && (A = arrCur) && (i < 6)) { // Total normal rainfall
            x;
            break;
        } else if ((E = tNewRainfall) && (A = arrNew) && (i < 6)) { // Total rainfall for 2018
            x;
            break;
        }
    }
    return final;
}

double calcDelta(double E, double *A, double *B) {
    double hi, lo, delta;
    double final;

    for (int i = 0; i < 6; i++) {
        double lo, hi, final, temp;

        if ((E = delta) && (A = arrCur) && (B = arrNew) && (i < 6)) {  // 2018 drier than norma

            if (i == 0) {
                lo = A[i];
                break;
            } else if (i == 1) {
                hi = B[i];
            }

            while ((i < 6) && (i != 0)) {
                if (lo > hi) {
                    temp = lo;
                    lo = hi;
                    hi = temp;
                    iPtr = i;
                }
            }
            highest = hi;
            delta = ((B[i] - A[i]));
        }
    }
    return delta;
}

int adapt(double E) {
    double i = ceil(E / 40 * 100);
    int o = i;
    return o;
}

void run() {
    for (int i = 0; i < 6; i++) {
        printf("%.1f %7.1f %7s %s %s", arrCur[i], arrNew[i], "* ", months[i], "data\n");
    }

    puts("\nRainfall comparison for January to June 2018");
    for (int iPtr = 0; iPtr < 6; iPtr++) {
        // displayYc = display Y co-ordinates
        printf("%-8s |%s\n |%s\n |%s\n", months[iPtr], displayYc(adapt(arrCur[iPtr])), displayYc(adapt(arrNew[iPtr])));
    }
    puts(LEGEND);

    printf("Total normal rainfall was %.1f mm.\n\nTotal rainfall for 2018 was %.1f mm.\n\n", tCurRainfall,
           tNewRainfall);
    printf("2018 was a drier year than normal by %.1f mm.", delta);

    printf("\n\nThe month with the highest rainfall was %s", months[iPtr]);
}

int main() {
    run();
    return 0;
}













