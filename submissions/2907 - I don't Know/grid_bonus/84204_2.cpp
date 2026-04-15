#include <iostream>
#include <algorithm>
using namespace std;

long long a[100005], L[100005], R[100005], t, n, i;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (cin >> t; t-- && cin >> n;) {
        for (i = 0; i < n; ++i) cin >> a[i];
        L[0] = R[0] = a[0];
        for (i = 1; i < n; ++i) {
            L[i] = a[i] < L[i-1] ? a[i] : min(a[i], R[i-1]);
            R[i] = a[i] > R[i-1] ? a[i] : max(a[i], L[i-1]);
        }
        for (a[i = n - 1] = L[n - 1]; i--;) 
            a[i] = max(L[i], min(a[i+1], R[i]));
        for (i = 0; i < n; ++i) 
            cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
}