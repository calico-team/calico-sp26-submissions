#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;



long long total_cost(const vector<long long>& top, const vector<long long>& bottom) {
    int n = top.size();
    long long cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += abs(top[i] - bottom[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        cost += abs(bottom[i] - bottom[i+1]);
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        
       
        vector<long long> b = A;
        bool changed;
        do {
            changed = false;
           
            vector<long long> new_b = b;
            for (int i = 0; i < N; ++i) {
                if (N == 1) {
                    new_b[i] = A[0];
                } else if (i == 0) {
                    new_b[i] = (A[0] + b[1]) / 2;
                } else if (i == N - 1) {
                    new_b[i] = (A[N-1] + b[N-2]) / 2;
                } else {
                    long long arr[3] = {A[i], b[i-1], b[i+1]};
                    sort(arr, arr + 3);
                    new_b[i] = arr[1];
                }
            }
            if (new_b != b) {
                changed = true;
                b = new_b;
            }
        } while (changed);
        
       
        if (total_cost(A, A) <= total_cost(A, b)) {
            b = A;
        }
        
        for (int i = 0; i < N; ++i) {
            cout << b[i] << " \n"[i == N-1];
        }
    }
    return 0;
}