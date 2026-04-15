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
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[n/2] << " ";
    }
}

int main() {
    cin.tie(0);     
    ios_base::sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
 
    return 0;
}