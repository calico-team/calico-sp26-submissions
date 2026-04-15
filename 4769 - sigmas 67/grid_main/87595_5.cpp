#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N;
    cin >> N;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];


    vector<ll> L(N);
    vector<ll> R(N);
    vector<ll> b(N);

    L[0] = a[0];
    R[0] = a[0];

    for (int i = 1; i < N; i++) {

        if (a[i] < L[i - 1]){
            L[i] = a[i];
            R[i] = L[i - 1];

        } else if (a[i] > R[i - 1]){
            L[i] = R[i - 1];
            R[i] = a[i];
        } else {
            L[i] = a[i];
            R[i] = a[i];
        }
    }



    b[N - 1] = R[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        if (b[i + 1] < L[i]) b[i] = L[i];
        else if (b[i + 1] > R[i]) b[i] = R[i];
        
        else b[i] = b[i + 1];
    }

    for (int i = 0; i < N; i++){
        if (i) cout << ' ';
        cout << b[i];
    }


    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}