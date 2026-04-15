#include <bits/stdc++.h>
using namespace std;

void slv(){
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &x : a) cin >> x;
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        long long v1 = abs(a[i]-b[i-1]) + 0;
        long long v2 = abs(a[i]-a[i]);
        if (v1 <= v2) b[i] = b[i-1];
        else b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << (i + 1 < n ? ' ' : '\n');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) slv();
    return 0;
}