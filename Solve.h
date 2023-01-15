#pragma once
#include <queue>

class Solver{

public:

    unsigned int solution(int N, double *a);

    unsigned int solution_2(int N, double *a);

    int rec(int a, int b, double *c);
};