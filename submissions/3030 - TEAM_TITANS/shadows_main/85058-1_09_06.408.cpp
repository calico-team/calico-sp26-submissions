#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


void solve() {
    ll n;
    cin >> n;
    vector <ll> l1(n);
    vector <ll> l2(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        ll x1 = 0;
        for (auto &p : s){
            x1 += (p == '#');
        }
        l1[i] = x1;
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        ll x1 = 0;
        for (auto &p : s){
            x1 += (p == '#');
        }
        l2[i] = x1;
    }
    ll a1 = 0; ll a2 = 0;
    for (int i = 0; i < n; i++){
        a1 += l1[i] * l2[i];
        a2 += max(l1[i], l2[i]);
    }
    cout << a1 << " " << a2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}