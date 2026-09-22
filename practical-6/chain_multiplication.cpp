#include <iostream>
using namespace std;

int main(){
    int n = 5;

    int p[] = {5, 10, 3, 12, 5, 50};

    int c[10][10] = {0};
    int k[10][10] = {0};

    for(int d = 1; d < n; d++){
        for(int i = 1; i <= n-d; i++){
            int j = i + d;
            int min = 99999;

            for(int x = i; x < j; x++){
                int q = c[i][x] + c[x+1][j]
                      + p[i-1] * p[x] * p[j];

                if(q < min){
                    min = q;
                    k[i][j] = x;
                }
            }
            c[i][j] = min;
        }
    }

    cout << "\nMinimum cost = " << c[1][n]<<endl;

    return 0;
}