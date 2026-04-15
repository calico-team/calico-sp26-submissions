#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()  {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    map<pair<int,int>,int> lis;
    int curx = -1;
    int cury = -1;
    for (int i = 0; i < k; i++)  {
        int x, y;
        cin >> x >> y;
        if (i == 0)  {
            curx = x;
            cury = y;
        }
        lis[{x,y}] = i;
    }
    curx += q;
    cury += p;
    curx %= n;
    cury %= m;
    while (true)  {
        //cout << "WEEGW " << curx << ' ' << cury << endl;
        if (lis.find({curx, cury}) != lis.end())  {
            cout << lis[{curx, cury}] << endl;
            return;
        }
        curx += q;
        cury += p;
        curx %= n;
        cury %= m;
        //cout << "WEGWEG " <<curx << ' ' << cury << endl;
    }
}

signed main()   {
    int t;
    t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}