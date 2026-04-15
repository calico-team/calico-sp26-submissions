#include <iostream>
#include <vector>

using namespace std;

void solve() {
long long x_g, y_g, x_m, y_m;
cin >> x_g >> y_g >> x_m >> y_m;
vector<vector<char>> grid(13000, vector<char>(13000, 0));
int start_mx = 6500;
int start_my = 6500;
int start_gx = x_g - x_m + 6500;
int start_gy = y_g - y_m + 6500;
vector<pair<int, int>> curr_g;
vector<pair<int, int>> curr_m;
curr_g.push_back({start_gx, start_gy});
curr_m.push_back({start_mx, start_my});
grid[start_gx][start_gy] = 1;
grid[start_mx][start_my] = 2;
long long total_m = 1;
long long time_tick = 1;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
while (!curr_m.empty()) {
if (time_tick % 2 == 0) {
vector<pair<int, int>> next_g;
for (int a = 0; a < (int)curr_g.size(); a++) {
for (int b = 0; b < 4; b++) {
int nx = curr_g[a].first + dx[b];
int ny = curr_g[a].second + dy[b];
if (nx >= 0 && nx < 13000 && ny >= 0 && ny < 13000) {
if (grid[nx][ny] == 0) {
grid[nx][ny] = 1;
next_g.push_back({nx, ny});
}
}
}
}
curr_g = next_g;
}
if (time_tick % 7 == 0) {
vector<pair<int, int>> next_m;
for (int a = 0; a < (int)curr_m.size(); a++) {
for (int b = 0; b < 4; b++) {
int nx = curr_m[a].first + dx[b];
int ny = curr_m[a].second + dy[b];
if (nx >= 0 && nx < 13000 && ny >= 0 && ny < 13000) {
if (grid[nx][ny] == 0) {
grid[nx][ny] = 2;
total_m++;
next_m.push_back({nx, ny});
}
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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
if (cin >> t) {
for (int a = 0; a < t; a++) {
solve();
}
}
return 0;
}