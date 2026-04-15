#include <bits/stdc++.h>
using namespace std;

void slv() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> b(n, a[0]);
    for(int i = 1; i < n; i++) b[i] = a[0];
    for (int i = 0; i < n; i++)
        cout << b[i] << (i + 1 < n ? ' ' : '\n');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) slv();
    return 0;
}