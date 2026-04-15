// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, l, w, e, r;
    cin >> t;
    for (int times = 0; times < t; times++){
        cin >> l >> w >> e >> r;
        int per = 2*l + 2*w;
        cout << e / (per*r) << endl;
    }
    return 0;
}
