// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--){
	    int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << c/(a*b*d) << "\n";
    }
}
