#include <iostream>
#include <vector>
using namespace std;
long long px[100005];
long long py[100005];
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
if (!(cin >> t)) return 0;
while (t > 0) {
long long k, n, m, p, q;
cin >> k >> n >> m >> p >> q;
for (int a = 0; a < k; a++) {
cin >> px[a] >> py[a];
}
vector<long long> mem_x(n, -1);
long long cx = px[0];
long long cycle_x = 0;
while (true) {
if (mem_x[cx] == -1) {
mem_x[cx] = cycle_x;
} else {
break;
}
cx = (cx + q) % n;
cycle_x = cycle_x + 1;
}
vector<long long> mem_y(m, -1);
long long jump_y = (cycle_x * p) % m;
long long cy = 0;
long long cycle_y = 0;
while (true) {
if (mem_y[cy] == -1) {
mem_y[cy] = cycle_y;
} else {
break;
}
cy = (cy + jump_y) % m;
cycle_y = cycle_y + 1;
}
int ans = -1;
long long min_steps = -1;
long long full_cycle = cycle_x * cycle_y;
for (int a = 0; a < k; a++) {
long long tx = px[a];
long long ty = py[a];
long long sx = mem_x[tx];
if (sx == -1) continue;
long long cur_y = (py[0] + sx * p) % m;
long long need_y = (ty - cur_y) % m;
if (need_y < 0) {
need_y = need_y + m;
}
long long jumps = mem_y[need_y];
if (jumps != -1) {
long long total = sx + jumps * cycle_x;
if (total == 0) {
total = full_cycle;
}
if (min_steps == -1 || total < min_steps) {
min_steps = total;
ans = a;
}
}
}
cout << ans << "\n";
t = t - 1;
}
return 0;
}