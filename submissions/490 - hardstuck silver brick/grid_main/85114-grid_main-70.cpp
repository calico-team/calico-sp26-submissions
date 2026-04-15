#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        if (n == 1) {
            cout << arr[0] << endl;
            return 0;
        }

        vector<ll> l_bound(n), r_bound(n);
        ll l = arr[0], r = arr[0];
        l_bound[0] = l;
        r_bound[0] = r;

        for (int i = 1; i < n; i++) {
            ll a = arr[i];
            if (a < l) {
                r = l;
                l = a;
            } else if (a > r) {
                l = r;
                r = a;
            } else {
                l = a;
                r = a;
            }
            l_bound[i] = l;
            r_bound[i] = r;
        }

        vector<ll> res(n);
        res[n - 1] = r_bound[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            ll nxt = res[i + 1];
            if (nxt < l_bound[i]) res[i] = l_bound[i];
            else if (nxt > r_bound[i]) res[i] = r_bound[i];
            else res[i] = nxt;
        }

        for (int i = 0; i < n; i++) cout << res[i] << " ";
    }
}