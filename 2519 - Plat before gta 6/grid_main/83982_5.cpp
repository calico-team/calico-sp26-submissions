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

    int ans = 1e18;
    vector<int> arr;
    if (n == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    vector<int> b = {a[i], a[j], a[k]};
                    int cur = 0;
                    for (int i = 0; i < n - 1; i++) cur += abs(a[i] - a[i + 1]);
                    for (int i = 0; i < n - 1; i++) cur += abs(b[i] - b[i + 1]);
                    for (int i = 0; i < n; i++) cur += abs(a[i] - b[i]);

                    if (ans > cur) {
                        ans = cur;
                        arr = b;
                    }
                }
            }
        }
    } else if (n == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> b = {a[i], a[j]};
                int cur = 0;
                for (int i = 0; i < n - 1; i++) cur += abs(a[i] - a[i + 1]);
                for (int i = 0; i < n - 1; i++) cur += abs(b[i] - b[i + 1]);
                for (int i = 0; i < n; i++) cur += abs(a[i] - b[i]);

                if (ans > cur) {
                    ans = cur;
                    arr = b;
                }
            }
        }
    } else if (n == 1) {
        arr = a;
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