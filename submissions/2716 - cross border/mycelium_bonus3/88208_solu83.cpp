#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
long long x_g, y_g, x_m, y_m;
cin >> x_g >> y_g >> x_m >> y_m;
map<pair<long long, long long>, char> grid;
vector<pair<long long, long long>> curr_g;
vector<pair<long long, long long>> curr_m;
curr_g.push_back({x_g, y_g});
curr_m.push_back({x_m, y_m});
grid[{x_g, y_g}] = 1;
grid[{x_m, y_m}] = 2;
long long total_m = 1;
long long time_tick = 1;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
while (!curr_m.empty()) {
if (time_tick % 2 == 0) {
vector<pair<long long, long long>> next_g;
for (int a = 0; a < curr_g.size(); a++) {
for (int b = 0; b < 4; b++) {
long long nx = curr_g[a].first + dx[b];
long long ny = curr_g[a].second + dy[b];
if (grid[make_pair(nx, ny)] == 0) {
grid[make_pair(nx, ny)] = 1;
next_g.push_back({nx, ny});
}
}
}
curr_g = next_g;
}
if (time_tick % 7 == 0) {
vector<pair<long long, long long>> next_m;
for (int a = 0; a < curr_m.size(); a++) {
for (int b = 0; b < 4; b++) {
long long nx = curr_m[a].first + dx[b];
long long ny = curr_m[a].second + dy[b];
if (grid[make_pair(nx, ny)] == 0) {
grid[make_pair(nx, ny)] = 2;
total_m++;
next_m.push_back({nx, ny});
}
}
}
curr_m = next_m;
}
time_tick++;
}
cout << total_m << "\n";
}
int main() {
int t;
if (cin >> t) {
for (int a = 0; a < t; a++) {
solve();
}
}
return 0;
}