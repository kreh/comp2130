//
// Created by Dave Aldrich on 1/26/2019.
//
#pragma once

#define RAINFALL_HEADER
#ifndef LEGEND
#define LEGEND "LEGEND:\n * - normal rainfall for a given month\n! - 2018 rainfall for a given month"
#define INIT 0
#endif

char displayYc();

char getSymbol(int index);

double calcHiLo(double E, double *A);

double calcDelta(double E, double *A, double *B);

int adapt(double E);

void generateGraphLayout();

double *generateGraph(int *index);
