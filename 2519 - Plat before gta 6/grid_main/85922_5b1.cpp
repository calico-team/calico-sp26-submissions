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

#define int long long
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(all(a));

    vector<int> arr;

    if (n % 2 == 0) {
        int b = a[n / 2 - 1];
        int c = a[n / 2];

        if ((b + c) % 2) arr = a;
        else {
            int d = (b + c) / 2;
            for (int i = 0; i < n; i++) arr.push_back(d);
        }
    }else {
        for (int i = 0; i < n; i++) arr.push_back(a[n / 2]);
    }

    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << arr.back();
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