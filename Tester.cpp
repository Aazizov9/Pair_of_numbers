#include "Tester.h"



void Tester::fib()
{
    unsigned long long int f1 = 0, f2 = 1, fn;

    for (int j = 1; j < N;j++)
    {
            fn = f1 + f2;
            a[j-1]=fn;
            f1 = f2;
            f2 = fn;
            //cout<<fn<<"   "<<endl;

    }
}

void Tester::fib_2(int x)
{
    unsigned long long int f1 = 0, f2 = 1, fn;

    for (int j = 1; j < x+2;j++)
    {
        fn = f1 + f2;
        a[j-1]=fn;
        f1 = f2;
        f2 = fn;
        //cout<<fn<<"   "<<endl;

    }
}


void Tester::test_1_fib() {

    if (N > 1) {
        double start, stop;
        double average_time;
        fib();
        double count=0;
        start = clock();
        bool b = 1;

        for (int i = 1; i < N - 1; i++) {
            int k = solver->solution(a[i],&count);
            //    cout<<"k: "<<k<<"  i: "<<i<<"  ai: "<<a[i]<< endl;
            if (k != i) b = 0;
        }
        if (b == 1) {
            stop = clock();
            cout << "test_Sol_1_fib: passed " << endl;
            average_time = (double) (stop - start) / CLOCKS_PER_SEC;
            cout << "test_Sol_1_fib: " << average_time << endl;
        } else cout << "test_Sol_1_fib: fail " << endl;

        //  int k= rand() % 3 +1;

        //  return 1;
    }
    cout<<endl;

}

void Tester::test_2_fib() {


    double start, stop;
    double average_time;
    double count=0;

    start = clock();
    bool b=1;

    for (int i = 1; i < N-1; i++)
    {
        int k = solver->solution_2(a[i], &count);
     //   cout<<"k: "<<k<<"  i: "<<i<<"  ai: "<<a[i]<< endl;
        if (k != i) b=0;
    }
    if(b==1) {
        stop = clock();
        cout << "test_Sol_2_fib: passed " << endl;
        average_time = (double) (stop - start) / CLOCKS_PER_SEC;
        cout << "time_Sol_2_fib: " << average_time << endl;
    }

    else cout << "test_Sol_2_fib: fail " << endl;

cout<<endl;
}



void Tester::test_2_1() {
    double start, stop;
    double average_time;
    double count=0;
    start = clock();


    for (int i = 1; i < N-1; i++)
    {
        int k = solver->solution(a[i]+1,&count);
        //   cout<<"k: "<<k<<"  i: "<<i<<"  ai: "<<a[i]<< endl;

    }

        stop = clock();
        average_time = (double) (stop - start) / CLOCKS_PER_SEC;
        cout << "time_2_Sol_1: " << average_time << endl;

}



void Tester::test_2_2() {
    double start, stop;
    double average_time;

    double count=0;
    start = clock();
    for (int i = 1; i < N-1; i++)
    {
        int k = solver->solution_2(a[i]+1, &count);
        //   cout<<"k: "<<k<<"  i: "<<i<<"  ai: "<<a[i]<< endl;

    }
        stop = clock();
        average_time = (double) (stop - start) / CLOCKS_PER_SEC;
        cout << "time_2_Sol_2: " << average_time << endl;

}


void Tester::test_3_1_100_1000(int x, int y) {
    myfile.open ("example_1.csv");

    clock_t start, stop;
    double average_time;
    double count;
    fib_2(y);
    myfile << "solution_1" <<  ";" <<" n "<< ";" << "t/k"<<endl;

    for (int i = x; i < y; i+=1)
    {
        start = clock();

        int k = solver->solution(a[i]-1, &count);

        stop = clock();
        average_time = (double) (stop - start) / CLOCKS_PER_SEC;

        myfile.setf(ios::scientific);
        myfile << average_time  <<";"<< a[i]-1 <<";"<< average_time/count <<endl;

    }

   //
   // cout << "time_3_Sol_1  " <<x<<" - "<<y << ":   "<< average_time << endl;
   // myfile << "time_3_Sol_1 average_time;" <<x<<" - "<<y << ":  ;"<< average_time << endl;


}



void Tester::test_3_2_100_1000(int x, int y) {
    fib_2(y);

    clock_t start, stop;
    double average_time;
    double count;
    myfile <<endl;
    myfile << "solution_2" <<  ";" <<" n "<< ";" << "t/k"<<endl;

    start = clock();
    for (int i = x; i < y; i+=2)
    {
        start = clock();
        int k = solver->solution_2(a[i]-1, &count);
         //  cout<<"k: "<<k<<"  i: "<<i<<"  ai: "<<a[i]+1<< endl;
        stop = clock();
        average_time = (double) (stop - start) / CLOCKS_PER_SEC;
        myfile.setf(ios::scientific);
        myfile << average_time  <<";"<< a[i]-1 <<";"<< average_time/count <<endl;


    }
    cout<<"****************";
  //  stop = clock();
    //average_time = (double) (stop - start) / CLOCKS_PER_SEC;
    //cout << "time_3_Sol_2  " <<x<<" - "<<y<< ":  "<<average_time << endl;


}




void Tester::test_4_1_r(int x, int y) {

    clock_t start, stop;
    double average_time;
     double count;

    myfile.open ("example_2.csv");
    myfile <<endl;
    myfile << "solution_1" <<  ";" <<" n "<< ";" << "t/k"<<endl;

    for (int i =0; i<y; i++){
        x+=100;
        start = clock();
        int k= solver->solution(x,&count );
        stop = clock();
        average_time = (double) (stop - start) / CLOCKS_PER_SEC;
        myfile.setf(ios::scientific);
        myfile << average_time  <<";"<< x <<";"<< average_time/count <<endl;
    }

    cout<<"&****************&";

}


void Tester::test_4_2_r(int y) {
    fib_2(y);


}