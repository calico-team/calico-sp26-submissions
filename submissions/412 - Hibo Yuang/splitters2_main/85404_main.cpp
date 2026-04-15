#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e18;
const ll MOD = 1e9 + 7;
const ll MAX2 = 41, MAX3 = 27;
bool testcases = true;

ll nextPowerOf(ll v, ll b) {
    ll cur = 1;
    while (cur < v) cur *= b;
    return cur;
}

vector<int> baseChange(int len, ll val, ll base) {
    vector<int> uwu;
    while (val > 0) {
        uwu.push_back(val % base);
        val -= val % base;
        val /= base;
    }
    reverse(uwu.begin(), uwu.end());
    while (uwu.size() < len) uwu.push_back(-1);
    return uwu;
}

void solve() {
    ll p, a, b;
    cin >> p >> a >> b;
    cout << 1 + 2 * (a+b) << " " << 3 << endl;
    cout << ">v." << endl;
    for (; a > MAX2; a--) cout << ".SX" << endl << ".v." << endl;
    for (; b > MAX3; b--) cout << "XSX" << endl << ".v." << endl;
    __int128 denom = pow(2, a)*pow(3, b);
    for (int i = 0; i < a; i++) {
        denom /= 2;
        int uwu = (p-1)/denom;
        p -= uwu*denom;
        cout << ".S";
        if (uwu == 1) cout << ">";
        else cout << "X";
        cout << endl << ".v." << endl;
    }
    for (int i = 0; i < b; i++) {
        denom /= 2;
        int uwu = p/denom;
        p -= uwu*denom;
        if (uwu == 2) cout << "<";
        else cout << "X";
        cout << "S";
        if (uwu >= 1) cout << ">";
        else cout << "X";
        cout << endl <<".v." << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}