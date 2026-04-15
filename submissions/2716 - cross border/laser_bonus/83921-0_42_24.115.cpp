#include <iostream>
#include <map>
using namespace std;
long long x[100005];
long long y[100005];
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
if (!(cin >> t)) return 0;
while (t > 0) {
long long k, n, m, p, q;
cin >> k >> n >> m >> p >> q;
map<pair<long long, long long>, int> mp;
for (int i = 0; i < k; i++) {
cin >> x[i] >> y[i];
if (mp.count({x[i], y[i]}) == 0) {
mp[{x[i], y[i]}] = i;
}
}
long long cx = x[0];
long long cy = y[0];
int ans = -1;
long long limit = n * m;
for (long long step = 1; step <= limit; step++) {
cx = (cx + q) % n;
cy = (cy + p) % m;
if (mp.count({cx, cy})) {
ans = mp[{cx, cy}];
break;
}
if (cx == x[0] && cy == y[0]) {
break;
}
}
cout << ans << "\n";
t = t - 1;
}
return 0;
}