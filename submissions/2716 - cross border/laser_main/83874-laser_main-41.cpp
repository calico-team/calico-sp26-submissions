#include <iostream>
using namespace std;
long long x[100005];
long long y[100005];
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
if (!(cin >> t)) return 0;
while (t--) {
long long k, n, m, p, q;
cin >> k >> n >> m >> p >> q;
for (int i = 0; i < k; i++) {
cin >> x[i] >> y[i];
}
long long cx = x[0];
long long cy = y[0];
int ans = -1;
long long limit = n * m;
for (long long step = 1; step <= limit; step++) {
cx = (cx + q) % n;
cy = (cy + p) % m;
for (int i = 0; i < k; i++) {
if (cx == x[i] && cy == y[i]) {
ans = i;
break;
}
}
if (ans != -1) break;
}
cout << ans << "\n";
}
return 0;
}