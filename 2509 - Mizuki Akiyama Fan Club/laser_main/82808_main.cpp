#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define endl "\n"

constexpr int mod = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    map<int, int> ind;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (ind.find(arr[i]) != ind.end()) {
            arr[i] = ind[arr[i]];
        } else {
            ind[arr[i]] = curr;
            arr[i] = curr++;
        }
    }
    vector<pi> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        queries[i] = {l, r};
    }
    vector<pi> unsorted_queries = queries;
    int sqn = sqrt(n);
    sort(queries.begin(), queries.end(), [sqn](auto a, auto b) {
        int b1 = a.f/sqn;
        int b2 = b.f/sqn;
        if (b1 == b2) {
            return a.s < b.s;
        }
        return b1 < b2;
    });
    int distinct = 0;
    int prev = -1;
    int i = 0;
    int j = 0;
    vector<int> freq(n, 0);
    map<pi, int> ans;
    for (auto p: queries) {
        int l = p.f;
        int r = p.s;
        int b = l/sqn;
        if (b != prev) {
            prev = b;
            i = l;
            j = l;
            fill(freq.begin(), freq.end(), 0);
            freq[arr[i]]++;
            distinct = 1;
        }
        while (j < r) {
            j++;
            freq[arr[j]]++;
            if (freq[arr[j]] == 1) {
                distinct++;
            }
        }
        if (l > i) {
            while (l > i) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) {
                    distinct--;
                }
                i++;
            }
        } else if (l < i) {
            while (l < i) {
                i--;
                freq[arr[i]]++;
                if (freq[arr[i]] == 1) {
                    distinct++;
                }
            }
        }
        ans[p] = distinct;
    }
    for (auto p: unsorted_queries) {
        cout << ans[p] << endl;
    }
}
 
int main() {
    srand(time(0));
    cin.tie(0);     
    ios_base::sync_with_stdio(0);
 
    int t = 1;
    // cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
 
    return 0;
}