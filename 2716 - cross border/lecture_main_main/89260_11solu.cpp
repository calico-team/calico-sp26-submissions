#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct seat {
int r;
int c;
int u;
int v;
};
int pref[2005][2005];
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
}
}
vector<seat> empty_seats;
for(int row = 0; row < n; row++) {
for(int col = 0; col < m; col++) {
if(grid[row][col] == '-') {
seat s;
s.r = row;
s.c = col;
s.u = row + col + 1;
s.v = row - col + m;
empty_seats.push_back(s);
pref[s.u][s.v]++;
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
int best_u = -1;
int best_v = -1;
for(int a = 1; a + min_d < max_u; a++) {
for(int b = 1; b + min_d < max_v; b++) {
int count = pref[a + min_d][b + min_d] - pref[a - 1][b + min_d] - pref[a + min_d][b - 1] + pref[a - 1][b - 1];
if(count >= k) {
best_u = a;
best_v = b;
break;
}
}
if(best_u != -1) {
break;
}
}
int printed = 0;
for(int a = 0; a < empty_seats.size(); a++) {
if(empty_seats[a].u >= best_u && empty_seats[a].u <= best_u + min_d && empty_seats[a].v >= best_v && empty_seats[a].v <= best_v + min_d) {
cout << empty_seats[a].r << " " << empty_seats[a].c << "\n";
printed++;
if(printed == k) {
break;
}
}
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