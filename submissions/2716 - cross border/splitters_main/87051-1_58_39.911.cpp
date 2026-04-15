#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct frac {
long long num;
long long den;
};
int tot;
int row;
int col;
char grd[25][25];
frac mem[25][25];
frac add(frac x, frac y) {
__int128 d1 = x.den;
__int128 n1 = x.num;
__int128 d2 = y.den;
__int128 n2 = y.num;
__int128 n_den = d1 * d2;
__int128 n_num = n1 * d2 + n2 * d1;
__int128 t_num = n_num;
__int128 t_den = n_den;
while (t_den != 0) {
__int128 t = t_den;
t_den = t_num % t_den;
t_num = t;
}
__int128 g = t_num;
frac res;
res.num = (long long)(n_num / g);
res.den = (long long)(n_den / g);
return res;
}
frac dfs(int r, int c) {
if (r < 0 || r >= row || c < 0 || c >= col) {
frac res;
res.num = 1;
res.den = 1;
return res;
}
if (mem[r][c].den != -1) {
return mem[r][c];
}
char ch = grd[r][c];
if (ch == 'X' || ch == '.') {
frac res;
res.num = 0;
res.den = 1;
return mem[r][c] = res;
}
if (ch == '>') return mem[r][c] = dfs(r, c + 1);
if (ch == '<') return mem[r][c] = dfs(r, c - 1);
if (ch == '^') return mem[r][c] = dfs(r - 1, c);
if (ch == 'v') return mem[r][c] = dfs(r + 1, c);
if (ch == 'S') {
vector<frac> vld;
if (r - 1 >= 0) {
char nxt = grd[r - 1][c];
if (nxt == 'X' || nxt == '<' || nxt == '>' || nxt == '^') vld.push_back(dfs(r - 1, c));
}
if (r + 1 < row) {
char nxt = grd[r + 1][c];
if (nxt == 'X' || nxt == '<' || nxt == '>' || nxt == 'v') vld.push_back(dfs(r + 1, c));
}
if (c - 1 >= 0) {
char nxt = grd[r][c - 1];
if (nxt == 'X' || nxt == '^' || nxt == 'v' || nxt == '<') vld.push_back(dfs(r, c - 1));
}
if (c + 1 < col) {
char nxt = grd[r][c + 1];
if (nxt == 'X' || nxt == '^' || nxt == 'v' || nxt == '>') vld.push_back(dfs(r, c + 1));
}
frac sum;
sum.num = 0;
sum.den = 1;
for (int a = 0; a < vld.size(); a++) {
sum = add(sum, vld[a]);
}
__int128 n = sum.num;
__int128 d = sum.den;
d = d * vld.size();
__int128 tn = n;
__int128 td = d;
while (td != 0) {
__int128 t = td;
td = tn % td;
tn = t;
}
__int128 g = tn;
sum.num = (long long)(n / g);
sum.den = (long long)(d / g);
return mem[r][c] = sum;
}
frac res;
res.num = 0;
res.den = 1;
return res;
}
int main() {
if (!(cin >> tot)) return 0;
for (int a = 0; a < tot; a++) {
cin >> row >> col;
for (int b = 0; b < row; b++) {
string s;
cin >> s;
for (int c = 0; c < col; c++) {
grd[b][c] = s[c];
mem[b][c].den = -1;
}
}
frac ans = dfs(0, 0);
if (ans.num == 0) cout << "0 1" << endl;
else cout << ans.num << " " << ans.den << endl;
}
return 0;
}