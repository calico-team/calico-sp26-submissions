#include <iostream>
#include <vector>

using namespace std;

int main() {
long long tot;
if (!(cin >> tot)) return 0;
for (long long a = 0; a < tot; a++) {
long long vp, va, vb;
cin >> vp >> va >> vb;
long long sum_ab = va + vb;
long long div[150];
long long mod[150];
for (long long b = 0; b < va; b++) {
div[b] = 2;
}
for (long long b = va; b < sum_ab; b++) {
div[b] = 3;
}
long long rem = vp;
for (long long b = sum_ab - 1; b >= 0; b--) {
mod[b] = rem % div[b];
rem = rem / div[b];
}
long long fin_p = rem;
long long row = 4;
long long col = 3 * sum_ab + 3;
char grd[50][500];
for (long long x = 0; x < row; x++) {
for (long long y = 0; y < col; y++) {
grd[x][y] = '.';
}
}
grd[0][0] = '>';
grd[0][1] = 'v';
grd[1][1] = 'v';
grd[2][1] = '>';
for (long long y = 2; y < col; y++) {
grd[0][y] = '>';
}
for (long long b = 0; b < sum_ab; b++) {
long long pos = 3 * b + 2;
long long d = div[b];
long long m = mod[b];
grd[2][pos] = 'S';
grd[3][pos] = '>';
grd[3][pos + 1] = '>';
grd[3][pos + 2] = '^';
grd[2][pos + 2] = '>';
if (d == 3) {
if (m == 0) {
grd[1][pos] = 'X';
grd[2][pos + 1] = 'X';
} else if (m == 1) {
grd[1][pos] = '^';
grd[2][pos + 1] = 'X';
} else if (m == 2) {
grd[1][pos] = '^';
grd[2][pos + 1] = '^';
grd[1][pos + 1] = '^';
}
} else if (d == 2) {
if (m == 0) {
grd[1][pos] = 'X';
} else if (m == 1) {
grd[1][pos] = '^';
}
}
}
long long end_c = 3 * sum_ab + 2;
if (fin_p == 1) {
grd[2][end_c] = '^';
grd[1][end_c] = '^';
} else {
grd[2][end_c] = 'X';
}
cout << row << " " << col << "\n";
for (long long x = 0; x < row; x++) {
for (long long y = 0; y < col; y++) {
cout << grd[x][y];
}
cout << "\n";
}
}
return 0;
}