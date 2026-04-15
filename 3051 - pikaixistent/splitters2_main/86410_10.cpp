#include <algorithm>
#include <iostream>

using namespace std;

const int A = 100;
const int B = 100;

int rr2[A], rr3[B];
string ss[4];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		long long p; int a, b; cin >> p >> a >> b;
		for (int i = b - 1; i >= 0; i--)
			rr3[i] = p % 3, p /= 3;
		for (int i = a - 1; i >= 0; i--)
			rr2[i] = p % 2, p /= 2;
		for (int h = 0; h < 4; h++)
			ss[h] = "";
		for (int i = 0; i < a; i++)
			if (rr2[i] == 0) {
				ss[0] += ">v>";
				ss[1] += ".S^";
				ss[2] += ".X.";
				ss[3] += ">>>";
			} else {
				ss[0] += ">v>";
				ss[1] += ".S^";
				ss[2] += ".v.";
				ss[3] += ">>>";
			}
		for (int i = 0; i < b; i++)
			if (rr3[i] == 0) {
				ss[0] += ">v>";
				ss[1] += "XS^";
				ss[2] += ".X.";
				ss[3] += ">>>";
			} else if (rr3[i] == 1) {
				ss[0] += ">v>";
				ss[1] += "XS^";
				ss[2] += ".v.";
				ss[3] += ">>>";
			} else {
				ss[0] += ">v>";
				ss[1] += "vS^";
				ss[2] += "vv.";
				ss[3] += ">>>";
			}
		ss[0] += "X";
		ss[1] += ".";
		ss[2] += ".";
		ss[3] += ">";
		cout << "4 " << ss[0].length() << '\n';
		for (int h = 0; h < 4; h++)
			cout << ss[h] << '\n';
	}
	return 0;
}
