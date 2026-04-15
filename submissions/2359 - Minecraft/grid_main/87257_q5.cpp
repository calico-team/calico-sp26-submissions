#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        if(N == 0) { 
            cout << endl;
            continue;
        }
        long long tv = 0;
        for(int i = 0; i + 1 < N; i++) {
            tv += abs(A[i] - A[i + 1]);
        }
        vector<long long> temp = A;
        sort(temp.begin(), temp.end());
        long long med = temp[N / 2]; 
        long long l1 = 0;
        for(int i = 0; i < N; i++) {
            l1 += abs(A[i] - med);
        }
        if(tv <= l1) {
            for(int i = 0; i < N; i++) {
                if(i > 0) cout << " ";
                cout << A[i];
            }
            cout << endl;
        } else {
            for(int i = 0; i < N; i++) {
                if(i > 0) cout << " ";
                cout << med;
            }
            cout << endl;
        }
    }
    return 0;
}