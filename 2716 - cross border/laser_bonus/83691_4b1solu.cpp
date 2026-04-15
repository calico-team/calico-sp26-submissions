#include <iostream>
using namespace std;
long long x[100005];
long long y[100005];
int main() {
int t;
cin >> t;
while (t > 0) {
long long k, n, m, p, q;
cin >> k >> n >> m >> p >> q;
for (int i = 0; i < k; i++) {
cin >> x[i] >> y[i];
}
long long cx = x[0];
long long cy = y[0];
int ans = -1;
for (long long step = 1; step <= n * m; step++) {
cx = (cx + q) % n;
cy = (cy + p) % m;
bool found = false;
for (int i = 0; i < k; i++) {
if (cx == x[i] && cy == y[i]) {
ans = i;
found = true;
break;
}
}
if (found == true) {
break;
}
}
cout << ans << "\n";
t = t - 1;
}
return 0;
}