//
// Created by Dave Aldrich on 1/26/2019.
//
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define RAINFALL_HEADER
#ifndef LEGEND
#define LEGEND "LEGEND:\n* - normal rainfall for a given month\n! - 2018 rainfall for a given month\n"
#define SCALE "----1----2----3----4----5----6----7----8"
#endif

char *displayYc(int fromAdapt, char token);

char getSymbol();

double calcTotal(double A[]);

double calcDelta();

int adapt(double E);

void generateGraphLayout();

double *generateGraph(int *index);
