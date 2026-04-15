#include <iostream>
#include <string>
using namespace std;
int main() {
int t;
if (!(cin >> t)) return 0;
while (t > 0) {
string a;
string b;
cin >> a >> b;
int x = 0;
int len_a = a.length();
int len_b = b.length();
for (int y = 0; y < len_a; y++) {
if (x < len_b && a[y] == b[x]) {
x = x + 1;
} else {
a[y] = '#';
}
}
cout << a << "\n";
t = t - 1;
}
return 0;
}