#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct seat {
int r, c, u, v, aura;
};
bool compare_aura(const seat& a, const seat& b) {
return a.aura < b.aura;
}
void solve() {
int n, m, k;
cin >> n >> m >> k;
vector<string> grid(n);
for(int a = 0; a < n; a++) {
cin >> grid[a];
}
vector<seat> empty_seats;
for(int row = 0; row < n; row++) {
int left_hashes = 0;
vector<int> left_aura(m, 0);
for(int col = 0; col < m; col++) {
if(grid[row][col] == '#') {
left_hashes++;
} else {
left_aura[col] = left_hashes;
}
}
int right_hashes = 0;
vector<int> right_aura(m, 0);
for(int col = m - 1; col >= 0; col--) {
if(grid[row][col] == '#') {
right_hashes++;
} else {
right_aura[col] = right_hashes;
}
}
for(int col = 0; col < m; col++) {
if(grid[row][col] == '-') {
seat s;
s.r = row;
s.c = col;
s.u = row + col + 1;
s.v = row - col + m;
s.aura = min(left_aura[col], right_aura[col]);
empty_seats.push_back(s);
}
}
}
vector<vector<int>> pref(n + m + 5, vector<int>(n + m + 5, 0));
for(int a = 0; a < empty_seats.size(); a++) {
pref[empty_seats[a].u][empty_seats[a].v]++;
}
for(int u = 1; u <= n + m + 2; u++) {
for(int v = 1; v <= n + m + 2; v++) {
pref[u][v] = pref[u][v] + pref[u - 1][v] + pref[u][v - 1] - pref[u - 1][v - 1];
}
}
int low = 0, high = n + m + 2, min_d = high;
while(low <= high) {
int mid = low + (high - low) / 2;
bool possible = false;
for(int u = 1; u + mid <= n + m + 2; u++) {
for(int v = 1; v + mid <= n + m + 2; v++) {
int count = pref[u + mid][v + mid] - pref[u - 1][v + mid] - pref[u + mid][v - 1] + pref[u - 1][v - 1];
if(count >= k) {
possible = true;
break;
}
}
if(possible) break;
}
if(possible) {
min_d = mid;
high = mid - 1;
} else {
low = mid + 1;
}
}
vector<vector<seat>> seats_by_u(n + m + 5);
for(int a = 0; a < empty_seats.size(); a++) {
seats_by_u[empty_seats[a].u].push_back(empty_seats[a]);
}
long long best_aura_sum = -1;
vector<seat> best_choices;
for(int u = 1; u + min_d <= n + m + 2; u++) {
for(int v = 1; v + min_d <= n + m + 2; v++) {
int count = pref[u + min_d][v + min_d] - pref[u - 1][v + min_d] - pref[u + min_d][v - 1] + pref[u - 1][v - 1];
if(count >= k) {
vector<seat> window_seats;
for(int curr_u = u; curr_u <= u + min_d; curr_u++) {
for(int b = 0; b < seats_by_u[curr_u].size(); b++) {
if(seats_by_u[curr_u][b].v >= v && seats_by_u[curr_u][b].v <= v + min_d) {
window_seats.push_back(seats_by_u[curr_u][b]);
}
}
}
sort(window_seats.begin(), window_seats.end(), compare_aura);
long long current_aura_sum = 0;
for(int a = 0; a < k; a++) {
current_aura_sum += window_seats[a].aura;
}
if(best_aura_sum == -1 || current_aura_sum < best_aura_sum) {
best_aura_sum = current_aura_sum;
best_choices.clear();
for(int a = 0; a < k; a++) {
best_choices.push_back(window_seats[a]);
}
}
}
}
}
for(int a = 0; a < k; a++) {
cout << best_choices[a].r << " " << best_choices[a].c << "\n";
}
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
if(cin >> t) {
for(int a = 0; a < t; a++) {
solve();
}
}
return 0;
}