#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<int> a (n);
        for (int& x : a) cin >> x;
        vec<int> b = a;
        for (int i = 1; i < n-1; i++) {
            if (b[i] > b[i-1] && b[i] > b[i+1]) {
                b[i] = max(b[i-1], b[i+1]);
            }
            else if (b[i] < b[i-1] && b[i] < b[i+1]) {
                b[i] = min(b[i-1], b[i+1]);
            }
        }
        for (int x : b) cout << x << " ";
        cout << ln;
    }
}
