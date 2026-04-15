#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int k, n, m, dx, dy; cin >> k >> n >> m >> dy >> dx;
    vector <pair <int, int>> a(k);
    for (auto &[x, y] : a) cin >> x >> y;
    map <pair <int, int>, int> mp;
    int it = 1;
    for (auto &[x, y] : a){
        if(mp[{x,y}]==0)mp[make_pair(x, y)] = it++;
    }
    int x = a[0].first + dx, y = a[0].first + dy;
    x %= n, y %= m;
    while (mp[make_pair(x, y)] == 0) {
        //cout << x << ' ' << y << '\n';
        x += dx, y += dy;
        x %= n, y %= m;
    }
    //cerr<<"found:"<<x<<" "<<y<<"\n";
    cout << mp[make_pair(x, y)]-1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}