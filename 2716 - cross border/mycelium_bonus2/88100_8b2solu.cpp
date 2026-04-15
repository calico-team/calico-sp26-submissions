#include <iostream>
#include <vector>
using namespace std;
void solve() {
long long x_g, y_g, x_m, y_m;
cin >> x_g >> y_g >> x_m >> y_m;
int center = 15000;
vector<vector<char>> grid(30000, vector<char>(30000, 0));
vector<pair<int, int>> curr_g;
vector<pair<int, int>> curr_m;
curr_g.push_back({x_g + center, y_g + center});
curr_m.push_back({x_m + center, y_m + center});
grid[x_g + center][y_g + center] = 1;
grid[x_m + center][y_m + center] = 2;
long long total_m = 1;
long long time_tick = 1;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
while (!curr_m.empty()) {
if (time_tick % 7 == 0) {
vector<pair<int, int>> next_m;
for (int a = 0; a < curr_m.size(); a++) {
for (int b = 0; b < 4; b++) {
int nx = curr_m[a].first + dx[b];
int ny = curr_m[a].second + dy[b];
if (nx >= 0 && nx < 30000 && ny >= 0 && ny < 30000) {
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
if (time_tick % 2 == 0) {
vector<pair<int, int>> next_g;
for (int a = 0; a < curr_g.size(); a++) {
for (int b = 0; b < 4; b++) {
int nx = curr_g[a].first + dx[b];
int ny = curr_g[a].second + dy[b];
if (nx >= 0 && nx < 30000 && ny >= 0 && ny < 30000) {
if (grid[nx][ny] == 0) {
grid[nx][ny] = 1;
next_g.push_back({nx, ny});
}
}
}
}
curr_g = next_g;
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