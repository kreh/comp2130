//
// Created by Dave Aldrich on 1/26/2019.
//
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#ifndef LEGEND
#define LEGEND "LEGEND:\n* - normal rainfall for a given month\n! - 2018 rainfall for a given month\n"
#define SCALE "----1----2----3----4----5----6----7----8"
#endif

char *displayYc(int fromAdapt, char token);

double calcDelta();

double calcTotal(double *A);

int adapt(double E);

char *data();


