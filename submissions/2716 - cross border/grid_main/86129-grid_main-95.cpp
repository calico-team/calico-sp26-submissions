#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
int tot;
if (!(cin >> tot)) return 0;
for (int a = 0; a < tot; a++) {
int num;
cin >> num;
vector<int> top;
for (int b = 0; b < num; b++) {
int x;
cin >> x;
top.push_back(x);
}
vector<int> bot;
for (int b = 0; b < num; b++) {
bot.push_back(top[b]);
}
if (num <= 2) {
for (int b = 0; b < num; b++) {
cout << bot[b] << " ";
}
cout << endl;
continue;
}
for (int c = 0; c < 50; c++) {
bool chg = false;
for (int b = 1; b < num - 1; b++) {
int lft = bot[b - 1];
int rgt = bot[b + 1];
int mid = top[b];
vector<int> tmp;
tmp.push_back(lft);
tmp.push_back(rgt);
tmp.push_back(mid);
sort(tmp.begin(), tmp.end());
int bst = tmp[1];
if (bot[b] != bst) {
bot[b] = bst;
chg = true;
}
}
for (int b = num - 2; b > 0; b--) {
int lft = bot[b - 1];
int rgt = bot[b + 1];
int mid = top[b];
vector<int> tmp;
tmp.push_back(lft);
tmp.push_back(rgt);
tmp.push_back(mid);
sort(tmp.begin(), tmp.end());
int bst = tmp[1];
if (bot[b] != bst) {
bot[b] = bst;
chg = true;
}
}
if (chg == false) {
break;
}
}
for (int b = 0; b < num; b++) {
cout << bot[b] << " ";
}
cout << endl;
}
return 0;
}