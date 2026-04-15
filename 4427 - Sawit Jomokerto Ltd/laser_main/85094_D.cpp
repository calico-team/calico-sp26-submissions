#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t; cin >> t;
    while (t--){
        set <pair <ll, ll>> s;
        map <pair <ll, ll>, ll> check;
        ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        ll curx = 0, cury = 0, stx = 0, sty = 0;
        for (int i = 0; i < a; i++){
            ll l, r; cin >> l >> r;
            if (i == 0){
                curx = l; stx = l;
                cury = r; sty = r;
            }
            check[{l, r}] = i;
            s.insert({l, r});
        }
        vector <vector <bool>> vis(b + 1, vector <bool>(c + 1, false));
        bool found = false;
        while (!found){
            if (vis[curx][cury] == true) break;
            if (s.find({curx, cury}) != s.end() && (curx != stx || cury != sty)){
                found = true;
                break;
            }
            vis[curx][cury] = true;
            curx = (curx + d) % (b + 1);
            cury = (cury + e) % (c + 1);
        }
        if (!found) cout << 0 << endl;
        else cout << check[{curx, cury}] << endl;
    }
}