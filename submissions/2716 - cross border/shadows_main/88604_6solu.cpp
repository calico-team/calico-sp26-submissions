#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
int n;
cin >> n;
vector<string> shadow1(n);
for(int a = 0; a < n; a++) {
cin >> shadow1[a];
}
vector<string> shadow2(n);
for(int a = 0; a < n; a++) {
cin >> shadow2[a];
}
long long max_vol = 0;
long long min_vol = 0;
for(int a = 0; a < n; a++) {
long long count1 = 0;
for(int b = 0; b < n; b++) {
if(shadow1[a][b] == '#') {
count1++;
}
}
long long count2 = 0;
for(int b = 0; b < n; b++) {
if(shadow2[a][b] == '#') {
count2++;
}
}
max_vol += count1 * count2;
if(count1 > count2) {
min_vol += count1;
} else {
min_vol += count2;
}
}
cout << max_vol << " " << min_vol << "\n";
}
int main() {
int t;
if(cin >> t) {
for(int a = 0; a < t; a++) {
solve();
}
}
return 0;
}