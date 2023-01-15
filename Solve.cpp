
#include "Solve.h"
#include "algorithm"
#include "ctime"
#include "iostream"
using namespace std;


template <typename T>inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int Solver::rec(int a, int b, double *count) {
    *count+=1;

    if (a == 1 && b == 0) return 0;
    if (a == 1 && b == 1) return 0;
    //cout << a << " " << b << "    ";
    return rec(b, a % b, count) + a / b;
}


unsigned int Solver::solution(int n, double *count){

    *count=0;
 //   double start, stop;
   // double average_time;


   // start = clock();
    int ans = n - 1;
    for (int i = 2; i <= n / 2; i++) {
        if (gcd(n - i, i) != 1) continue;
        int tmp = rec(n - i, i, count);
        //cout << tmp << endl;
        ans = min(ans, tmp);
    }
   // cout<<k<<endl;
  //  stop= clock();
   // average_time = (double) (stop - start) / CLOCKS_PER_SEC;
   // cout << "time_Sol: " << average_time << endl;
    return ans;

}
unsigned int Solver::solution_2(int n, double *count) {
        *count=0;

        int ans = 1e9;
        queue<pair<pair<int,int>,int>> q;

        q.push({{1, 1}, 0});

        while (!q.empty()) {
            *count+=1;
            int x = q.front().first.first, y = q.front().first.second;
            int c = q.front().second;
            q.pop();

            if (x == n || y == n) ans = min(ans, c);

            if (x + y <= n) {
                q.push({{x + y, y}, c + 1});
                q.push({{x, x + y}, c + 1});
            }
        }

       // cout << ans;

        return ans;
    }


