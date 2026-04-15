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
vector<int> top(num);
for (int b = 0; b < num; b++) {
cin >> top[b];
}
vector<int> lft(num);
vector<int> rgt(num);
lft[0] = top[0];
rgt[0] = top[0];
for (int b = 1; b < num; b++) {
if (top[b] < lft[b - 1]) {
lft[b] = top[b];
rgt[b] = lft[b - 1];
} else if (top[b] > rgt[b - 1]) {
lft[b] = rgt[b - 1];
rgt[b] = top[b];
} else {
lft[b] = top[b];
rgt[b] = top[b];
}
}
vector<int> bot(num);
bot[num - 1] = lft[num - 1];
for (int b = num - 2; b >= 0; b--) {
vector<int> tmp;
tmp.push_back(lft[b]);
tmp.push_back(rgt[b]);
tmp.push_back(bot[b + 1]);
sort(tmp.begin(), tmp.end());
bot[b] = tmp[1];
}
for (int b = 0; b < num; b++) {
cout << bot[b] << " ";
}
cout << endl;
}
return 0;
}