// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while (t--) {
        int n, p, r, k;
        cin >> n>>p>>r>>k;
        int def = 0;
        bool ok=1;
        for (int i = 0; i < n; i ++){
            //cout << p << ' ';
            int x;
            cin >> x;
            p -= x;
            if (p < 0) {
                ok=0;
                
            }
            def++;
            if (def >= k) {
                def -= k;
                p += r;
            }
        }
        if (!ok) {
            cout << "nah i’d lose";
        } else {
            cout << "nah i’d win";
        }
        if (t!=0) {
            cout << '\n';
        }

    }
    
    
}
