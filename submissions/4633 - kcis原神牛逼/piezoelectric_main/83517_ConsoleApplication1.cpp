#include<cctype>
#include <iostream>
using namespace std;
int main() {
	int T, a[5] = { 0 };
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> a[1] >> a[2] >> a[3] >> a[4];
		int s = 2 * (a[1] + a[2]) * a[4];
		cout << a[3] / s << endl;

	}
	return 0;
}