#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct seat {
int r;
int c;
int u;
int v;
int aura;
};
int pref[2005][2005];
vector<seat> seats_at[2005][2005];
void solve() {
int n, m, k;
cin >> n >> m >> k;
vector<string> grid(n);
for(int a = 0; a < n; a++) {
cin >> grid[a];
}
int max_u = n + m + 5;
int max_v = n + m + 5;
for(int a = 0; a < max_u; a++) {
for(int b = 0; b < max_v; b++) {
pref[a][b] = 0;
seats_at[a][b].clear();
}
}
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
int min_a = left_aura[col];
if (right_aura[col] < min_a) {
min_a = right_aura[col];
}
s.aura = min_a;
pref[s.u][s.v]++;
seats_at[s.u][s.v].push_back(s);
}
}
}
for(int a = 1; a < max_u; a++) {
for(int b = 1; b < max_v; b++) {
pref[a][b] = pref[a][b] + pref[a - 1][b] + pref[a][b - 1] - pref[a - 1][b - 1];
}
}
int low = 0;
int high = n + m + 2;
int min_d = high;
while(low <= high) {
int mid = low + (high - low) / 2;
bool possible = false;
for(int a = 1; a + mid < max_u; a++) {
for(int b = 1; b + mid < max_v; b++) {
int count = pref[a + mid][b + mid] - pref[a - 1][b + mid] - pref[a + mid][b - 1] + pref[a - 1][b - 1];
if(count >= k) {
possible = true;
break;
}
}
if(possible) {
break;
}
}
if(possible) {
min_d = mid;
high = mid - 1;
} else {
low = mid + 1;
}
}
long long best_aura_sum = -1;
vector<seat> best_choices;
for(int a = 1; a + min_d < max_u; a++) {
int aura_counts[1005] = {0};
int current_count = 0;
for(int curr_u = a; curr_u <= a + min_d; curr_u++) {
for(int curr_v = 1; curr_v <= 1 + min_d; curr_v++) {
for(int c = 0; c < (int)seats_at[curr_u][curr_v].size(); c++) {
aura_counts[seats_at[curr_u][curr_v][c].aura]++;
current_count++;
}
}
}
for(int b = 1; b + min_d < max_v; b++) {
if(current_count >= k) {
long long current_aura_sum = 0;
int needed = k;
for(int c = 0; c <= m; c++) {
if(aura_counts[c] > 0) {
int take = aura_counts[c];
if(take > needed) {
take = needed;
}
current_aura_sum += 1LL * take * c;
needed -= take;
if(needed == 0) {
break;
}
}
}
if(best_aura_sum == -1 || current_aura_sum < best_aura_sum) {
best_aura_sum = current_aura_sum;
best_choices.clear();
needed = k;
for(int c = 0; c <= m; c++) {
if(aura_counts[c] > 0) {
for(int curr_u = a; curr_u <= a + min_d; curr_u++) {
for(int curr_v = b; curr_v <= b + min_d; curr_v++) {
for(int d = 0; d < (int)seats_at[curr_u][curr_v].size(); d++) {
if(seats_at[curr_u][curr_v][d].aura == c) {
best_choices.push_back(seats_at[curr_u][curr_v][d]);
needed--;
if(needed == 0) {
break;
}
}
}
if(needed == 0) {
break;
}
}
if(needed == 0) {
break;
}
}
}
if(needed == 0) {
break;
}
}
}
}
for(int curr_u = a; curr_u <= a + min_d; curr_u++) {
for(int c = 0; c < (int)seats_at[curr_u][b].size(); c++) {
aura_counts[seats_at[curr_u][b][c].aura]--;
current_count--;
}
}
if(b + min_d + 1 < max_v) {
for(int curr_u = a; curr_u <= a + min_d; curr_u++) {
for(int c = 0; c < (int)seats_at[curr_u][b + min_d + 1].size(); c++) {
aura_counts[seats_at[curr_u][b + min_d + 1][c].aura]++;
current_count++;
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