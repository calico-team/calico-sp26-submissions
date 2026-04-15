#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve() {
    ll xg,yg,xm,ym;
    cin >> xg >> yg >> xm >> ym;
    xg += 150;
    yg += 150;
    xm += 150;
    ym += 150;
    // 1000 x 1000 grid just incase.
    // time, owner, x, y
    vector <vector <ll>> owned(301, vector <ll>(301, -1));
    priority_queue <vector <ll>, vector <vector<ll>>, greater <vector <ll>>> l1;
    l1.push({0, 0, xg, yg});
    l1.push({0,1, xm, ym});
    while (l1.size() >= 1){
        auto cur = l1.top();
        l1.pop();
        if (cur[2] < 0 || cur[2] > 300 || cur[3] < 0 || cur[3] > 300){
            continue;
        }
        if (owned[cur[2]][cur[3]] >= 0){
            continue;
        }
        owned[cur[2]][cur[3]] = cur[1]; 
        l1.push({cur[0] + (cur[1] == 0 ? 2 : 7), cur[1], cur[2] + 1, cur[3]});
        l1.push({cur[0] + (cur[1] == 0 ? 2 : 7), cur[1], cur[2] -1, cur[3]});
        l1.push({cur[0] + (cur[1] == 0 ? 2 : 7), cur[1], cur[2], cur[3] + 1});
        l1.push({cur[0] + (cur[1] == 0 ? 2 : 7), cur[1], cur[2], cur[3] - 1});
    }
    ll answ = 0;
    for (int i = 0; i <= 300; i++){
        for (int j = 0; j <= 300; j++){
            answ += owned[i][j];
        }
    }
    cout << answ << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}