/****
 * Name: Dave Aldrich
 * Student Number: T00593238
 * Seminar Number: 02
 * Due Date: February 5, 2019
 * Program Description:  Assignment #3: Rainfall program with functions and pointers
 ****/

#include "rainfall_header.h"


char *window(char *text, int W, int H) {
    // (width + newline) * height + null
    char *returnString = malloc((W + 1) * H + 1);
    // pointer for modification
    char *returnString_ptr = returnString;

    // width - (2 spaces + 2 pipes)
    int lineLength = W - 4;
    // text.length % lineLength
    int textLines = (sizeof(*text) / sizeof(char)) % lineLength;
    // height - lines of text - 2 bars
    int blankLines = H - textLines - 2;

    unsigned char
            h_char = 196,
            v_char = 179,
            h_char_topCorner_left = 218,
            h_char_topCorner_right = 191,
            h_char_bottomCorner_left = 192,
            h_char_bottomCorner_right = 217;
    // space for the line + \n
    char *blankLine = malloc(W + 1);
    char *blankLine_ptr = blankLine;
    // increment pointer and assign value to address in one line
    // equivalent to:
    // *blankLine_ptr = v_char;
    // blankLine_ptr++;
    *blankLine_ptr++ = v_char;
    // set W - 2 spaces
    blankLine_ptr = memset(blankLine_ptr, ' ', W - 2);
    // always remember to increment the pointer
    blankLine_ptr += W - 2;
    *blankLine_ptr++ = v_char;
    *blankLine_ptr++ = '\n';


    size_t textLen = strlen(text) - 1;


    char *topLine = malloc(W + 1);
    char *topLine_ptr = topLine;

    *topLine_ptr++ = h_char_topCorner_left;

    topLine_ptr = memset(topLine_ptr, h_char, W - 2);
    topLine_ptr += W - 2;
    *topLine_ptr++ = h_char_topCorner_right;
    *topLine_ptr++ = '\n';

    char *bottomLine = malloc(W + 1);
    char *bottomLine_ptr = bottomLine;
    *bottomLine_ptr++ = h_char_bottomCorner_left;

    bottomLine_ptr = memset(bottomLine_ptr, h_char, W - 2);

    bottomLine_ptr += W - 2;
    *bottomLine_ptr++ = h_char_bottomCorner_right;
    *bottomLine_ptr++ = '\n';

    returnString_ptr = memcpy(returnString_ptr, topLine, W + 1);
    // always remember to increment the pointer
    returnString_ptr += W + 1;

    if (blankLines < 0)
        return "Error: Please specify a larger height\n";

    for (int i = 0; i < blankLines / 2; i++) {
        // copying *blankLine* to returnString_ptr, to get the original address
        returnString_ptr = memcpy(returnString_ptr, blankLine, W + 1);
        returnString_ptr += W + 1;
    }

    for (int i = 0; i < textLines; i++) {

        *returnString_ptr++ = v_char;

        returnString_ptr = memset(returnString_ptr, ' ', ((W - textLen) / 2) - 1);
        returnString_ptr += (((W - textLen) / 2) - 1);

        returnString_ptr = memcpy(returnString_ptr, text, textLen + 1);
        returnString_ptr += textLen + 1;

        returnString_ptr = memset(returnString_ptr, ' ', ((W - textLen) / 2) - 1);
        returnString_ptr += (((W - textLen) / 2) - 1);

        *returnString_ptr++ = v_char;
        *returnString_ptr++ = '\n';

    }

    for (int i = 0; i < (blankLines / 2) + (blankLines % 2); i++) {
        returnString_ptr = memcpy(returnString_ptr, blankLine, W + 1);
        returnString_ptr += W + 1;
    }

    returnString_ptr = memcpy(returnString_ptr, bottomLine, W + 1);
    returnString_ptr += W + 1;
    *returnString_ptr++ = '\0';

    return returnString;
}

int main(void) {

    printf("%s", window("Hello World!", 20, 10));


}


char months[6][9] = {"January", "February", "March", "April", "May",
                     "June"}; // [6] is months len, [9] is for max allowed char alloc
double arrCurrentYear[6] = {5.4, 4.4, 4.1, 3.0, 5.6, 4.5};
double arrLastYear[6] = {3.1, 4.7, 4.2, 5.0, 4.0, 6.3};


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

double calcTotal(double *A) {
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

char *data() {

    char *sprintf_1_val = malloc(12345);
    char *sprintf_1 = sprintf_1_val;

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

    sprintf(sprintf_1, "Total normal rainfall was %.1f mm.\n\nTotal rainfall for 2018 was %.1f mm.\n\n",
            calcTotal(arrLastYear),
            calcTotal(arrCurrentYear));
    *sprintf_1 += *sprintf_1_val;

    sprintf(sprintf_1, "2018 was a drier year than normal by %.1f mm.", delta);
    *sprintf_1 += *sprintf_1_val;

    printf(sprintf_1, "\n\nThe month with the highest rainfall was %s (2018)\n", months[getHighestMonth()]);
    *sprintf_1 += *sprintf_1_val;

    free(sprintf_1);
}
