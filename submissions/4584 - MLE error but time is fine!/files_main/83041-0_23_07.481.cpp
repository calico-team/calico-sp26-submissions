#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

void solve() {
    string A, B;
    cin >> A >> B; 

    int j = 0;
    for (int i = 0; i < B.size(); i++) {
        while (A[j] != B[i]) {
            A[j++] = '#';
        }
        j++; 
    }
    for (; j < A.size(); j++) A[j] = '#';

    cout << A << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t; 
    while(t--)
        solve();
}