#include <iostream>
using namespace std;

const int a[][5] = {
    {1,4,0,2,3},
    {2,3,1,4,0},
    {4,0,2,3,1},
    {3,1,4,0,2},
    {0,2,3,1,4}};


int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        int my, nx;
        cin >> my >> nx;
        for (int i = 0 ; i < my ; ++i) {
            for (int j = 0 ; j < nx ; ++j) {
                if (j) printf(" ");
                printf("%d", a[i%5][j%5]);
            }
            printf("\n");
        }
    } 
    return 0;
}