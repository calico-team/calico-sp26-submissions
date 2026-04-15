#include <bits/stdc++.h>
using namespace std;

/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    int fx = 0;
    for(int i = 1; i < N; i++){
        fx += abs(A[i] - A[i - 1]);
    }
    if(N == 1){
        return A;
    }
    else if(N == 2){
        vector<int> c0 = {A[0], A[1]};
        vector<int> c1 = {A[1], A[0]};
        vector<int> ans;
        int mn = INT_MAX;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                vector<int> temp;
                temp.push_back(c0[i]);
                temp.push_back(c1[j]);
                int sum = fx;
                for(int i = 0; i < N; i++){
                    sum += abs(temp[i] - A[i]);
                }
                for(int i = 1; i < N; i++){
                    sum += abs(temp[i] - temp[i - 1]);
                }
                if(sum < mn){
                    mn = sum;
                    ans = temp;
                }
            }
        }
        return ans;
    }
    else{
        vector<int> c0 = {A[0], A[1]};
        vector<int> c1 = {A[0], A[1], A[2]};
        vector<int> c2 = {A[1], A[2]};
        vector<int> ans;
        int mn = INT_MAX;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 2; k++){
                    vector<int> temp;
                    temp.push_back(c0[i]);
                    temp.push_back(c1[j]);
                    temp.push_back(c2[k]);
                    int sum = fx;
                    for(int i = 0; i < N; i++){
                        sum += abs(temp[i] - A[i]);
                    }
                    for(int i = 1; i < N; i++){
                        sum += abs(temp[i] - temp[i - 1]);
                    }
                    if(sum < mn){
                        mn = sum;
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
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
