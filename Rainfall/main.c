/****
 * Name: Dave Aldrich
 * Student Number: T00593238
 * Seminar Number: 02
 * Due Date:  January 29, 2019
 * Program Description:  Assignment #2: Rainfall program with functions
 ****/

#include "rainfall_header.h"

char months[6][9] = {"January", "February", "March", "April", "May",
                     "June"}; // [6] is months len, [9] is for max allowed char alloc
double arrCurrentYear[6] = {5.4, 4.4, 4.1, 3.0, 5.6, 4.5};
double arrLastYear[6] = {3.1, 4.7, 4.2, 5.0, 4.0, 6.3};
int iPtr;

char *displayYc(int fromAdapt, char token) {
    char *space = malloc(fromAdapt + 1);
    space = memset(space, token, fromAdapt);
    return space;
}

// Current vs New delta calculation
double calcDelta() {
    double currentYear = calcTotal(arrCurrentYear);
    double lastYear = calcTotal(arrLastYear);
    return currentYear - lastYear;
}

double calcTotal(double A[]) {
    double final = 0.0;

    for (int i = 0; i < 6; i++) {
        final += A[i];
    }
    return final;
}

int adapt(double E) {
    double i = ceil(E / 8 * 40);
    int o = i;
    return o;
}

int getHighestMonth() {
    int index;
    double highest = 0.0;

    for (int i = 0; i < 6; i++) {
        double temp = arrCurrentYear[i];;
        if (temp > highest) {
            highest = temp;
            index = i;
        }
    }

    return index;
}

void run() {
    double delta = calcDelta();
    delta = delta < 0 ? delta * -1 : delta;

    puts("\nRAINFALL ASSIGNMENT - DAVE ALDRICH - COMP 2130\n");
    for (int i = 0; i < 6; i++) {
        printf("%.1f %7.1f %7s %s %s", arrLastYear[i], arrCurrentYear[i], "* ", months[i], "data\n");
    }
    puts("\nRainfall comparison for January to June 2018\n");
    for (int iPtr = 0; iPtr < 6; iPtr++) {
        char *lyd = displayYc(adapt(arrLastYear[iPtr]), '*');
        char *cyd = displayYc(adapt(arrCurrentYear[iPtr]), '!');
        printf("%-8s %8s%s\n %16s%s\n %16s%s\n", months[iPtr], "|", lyd, "|", cyd, "|",
               ""); // displayYc = display Y co-ordinates
        if (iPtr == 5)
            printf("%-8s %8s%s\n %16s%s\n %16s%s\n", months[iPtr], "|", lyd, "|", cyd, "|", SCALE);
    }

    puts(LEGEND);

    printf("Total normal rainfall was %.1f mm.\n\nTotal rainfall for 2018 was %.1f mm.\n\n",
           calcTotal(arrLastYear),
           calcTotal(arrCurrentYear));
    printf("2018 was a drier year than normal by %.1f mm.", delta);

    printf("\n\nThe month with the highest rainfall was %s (2018)\n", months[getHighestMonth()]);
}

int main() {
    run();
    return 0;
}
