#pragma once
#include "Solve.h"
#include "fstream"
#include <ctime>
#include <iostream>
using namespace std;


class Tester
{
private:
    Solver *solver;
public:
    ofstream myfile;
int N;

unsigned long long int *a;
unsigned long long int *b;
    Tester(int n) {
        N=n+2;
        a=new unsigned long long int[100];
        b=new unsigned long long int[100];
        test_1_fib();
        test_2_fib();
      //  test_2_1();
      //  test_2_2();

    }

    void test_3_1_100_1000(int a, int b);
    void test_3_2_100_1000(int a, int b);
    void test_4_1_r(int a, int b);
private:


    void fib();
    void fib_2(int x);

    void random(int a);

    void test_1_fib();
    void test_2_fib();
    void test_2_1();
    void test_2_2();

    void test_4_2_r(int a);
};