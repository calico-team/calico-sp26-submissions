#include <bits/stdc++.h>
using namespace std;
#include<map>
/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 *
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    // YOUR CODE HERE
    map<int ,int >c;
    for ( int i=0; i<n; i++ ){
        c[l[i]]++;
    }
    int m=0,ma=0;
    for ( auto i = c.begin(); i != c.end();i++){
        if ( c->second>m){
            m = c->second;
            ma= c->first
        }
    }
    vector < int >l;
    for ( int i=0; i<n; i++ ){
        l[i] = ma;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
