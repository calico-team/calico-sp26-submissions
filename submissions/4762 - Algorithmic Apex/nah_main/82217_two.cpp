#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvii = vector<vii>;

#define rep(i, a, b)  for (int i = int(a); i < int(b); i++)
#define repr(i, a, b) for (int i = int(a); i > int(b); i--)
#define cinn(a, n)    rep(_, 0, n) cin >> a[_];
#define all(x)        begin(x), end(x)
#define each(x, l)    for (auto x : l)

const int MOD = 1e9 + 7;

void solve() {
    int n, p, r, k;
    cin >> n >> p >> r >> k;

    vi a(n);
    cinn(a, n);

	ll health = p;
	rep(i,0,n){
		if(i != 0 && i % k == 0) health += r;
		health -= a[i];
		if(health < 0){
			cout << "nah i'd lose" << endl;
			return;
		}
	}
	cout << "nah i'd win" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) solve();
}
