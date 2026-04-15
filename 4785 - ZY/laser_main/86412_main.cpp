//
//  main.cpp
//  测试II
//
//  Created by Kevin on 2024/12/8.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    // YOUR CODE HERE
    int nx=X[0],ny = Y[0];
    while ( true){
        
        nx+=Q;
        ny+=P;
        nx=nx%N;
        ny = ny%M;
        for ( int i=0; i<K; i++ ){
            if ( X[i] == nx && Y[i] == ny){
                
                return i;
            }
        }
    
    }
    return 0;
}


int main() {
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            X[i] = a;
            Y[i] = b;
        }
        cout << solve(K, N, M, P, Q, X, Y) << endl;
    }
    return 0;
}
