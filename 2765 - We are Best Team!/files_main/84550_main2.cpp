#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void f() {
    string a, b;
    if (cin >> a >> b) {
        int n = a.length();
        int m = b.length();
        int bi = 0;

        for (int i = 0; i < n; i++) {
            if (bi < m && a[i] == b[bi]) {
                bi++;
            } else {
                a[i] = '#';
            }
        }
        cout << a << endl;
    }
}

int main() {

    int t;
    if (cin >> t) {
        while (t--) {
            f();
        }
    }

    return 0;
}