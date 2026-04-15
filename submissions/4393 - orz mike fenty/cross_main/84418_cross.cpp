#include <bits/stdc++.h>
using namespace std;

int t, n, m;

void solve() {
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = (2*i + j)%5;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}