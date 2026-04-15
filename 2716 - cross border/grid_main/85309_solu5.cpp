#include <iostream>
using namespace std;
long long e[10005];
int main() {
int t;
cin >> t;
while (t > 0) {
long long n, p, r, k;
cin >> n >> p >> r >> k;
for (int a = 1; a <= n; a++) {
cin >> e[a];
}
bool win = true;
for (int a = 1; a <= n; a++) {
p = p - e[a];
if (p < 0) {
win = false;
break;
}
if (a % k == 0) {
p = p + r;
}
}
if (win == true) {
cout << "nah i'd win\n";
} else {
cout << "nah i'd lose\n";
}
t = t - 1;
}
return 0;
}