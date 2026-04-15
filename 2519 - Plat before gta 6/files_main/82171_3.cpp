#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>
#include <array>
#include <functional>
#include <bitset>
using namespace std;

void baseIO(string s = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (s.size()){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

// #define int long long
#define all(x) (x).begin(), (x).end()

void solve(){
    string a;
    string b;
    cin >> a >> b;

    int j = 0;
    for (auto &c : a) {
        if (c == b[j]) {
            if (j == b.size()) {
                continue;
            }
            j++;
        } else {
            c = '#';
        }
    }

    cout << a;
}

signed main() {
    baseIO();

    int t;
    cin >> t;
    while (t--){
        solve(), cout << '\n';
    }

    return 0;
}