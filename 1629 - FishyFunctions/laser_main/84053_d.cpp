#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
while(t--) {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<int> x (k);
    vector<int> y (k);
    for(int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
    }
    int curx = x[0];
    int cury = y[0];
    curx += q;
    curx %= n;
    cury += p;
    cury %= m;
    bool found = false;
    while(curx != x[0] || cury != y[0]) {
        //cout << "Currently at (" << curx << "," << cury << ")\n";
        for(int i = 0; i < k; ++i) {
            if(curx == x[i] && cury == y[i]) {
                cout << i << '\n';
                found = true;
                break;
            }
        }
        if(found) break;
        curx += q;
        curx %= n;
        cury += p;
        cury %= m;
    }
    if(!found) {
        cout << "0\n";
    }
}
}