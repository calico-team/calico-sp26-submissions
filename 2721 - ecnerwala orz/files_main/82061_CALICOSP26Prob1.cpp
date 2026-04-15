// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a; cin >> a;
    string b; cin >> b;
    int p = 0;
    for (int i = 0; i < b.size(); i++) {
        while (a[p]!=b[i]) {a[p++]='#';}
        p++;
    }
    while (p<a.size()) {a[p++]='#';}
    cout << a << endl;
}

int main() {
	int T; cin >> T;
    while (T--) {solve();}
}
