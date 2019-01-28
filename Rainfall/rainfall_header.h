//
// Created by Dave Aldrich on 1/26/2019.
//
#pragma once

#define RAINFALL_HEADER
#ifndef LEGEND
#define LEGEND "LEGEND:\n* - normal rainfall for a given month\n! - 2018 rainfall for a given month"
#define SCALE "----1----2----3----4----5----6----7----8"
#endif

void *displayYc();

char getSymbol();

double calcTotal(double A, double *B);

double calcDelta(double A);

int adapt(double E);

void generateGraphLayout();

double *generateGraph(int *index);
