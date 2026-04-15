#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll time(ll x, ll y, ll gx, ll gy) {
    ll d = abs(x - gx) + abs(y - gy);
    return (d / 2) * 2 + (d % 2 == 1 ? 2 : 0);
}

ll bfs(ll gx, ll gy, ll mx, ll my) {
    queue<pair<pair<ll, ll>, ll>> q;
    set<pair<ll, ll>> st;

    if (time(mx, my, gx, gy) <= 0) return 0;

    q.push({{mx, my}, 0});
    st.insert({mx, my});
    ll res = 1; 

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        ll x = now.first.first;
        ll y = now.first.second;
        ll t = now.second;

        for (int i = 0; i < 4; i++) {
            ll nx = x + dir[i][0];
            ll ny = y + dir[i][1];

            if (st.find({nx, ny}) == st.end()) {
                st.insert({nx, ny});
                ll nt = t + 7;
             
                if (time(nx, ny, gx, gy) > nt) {
                    res++;
                    q.push({{nx, ny}, nt});
                }
    
            }
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll gx, gy, mx, my;
        cin >> gx >> gy >> mx >> my;
        cout << bfs(gx, gy, mx, my) << endl;
    }
}