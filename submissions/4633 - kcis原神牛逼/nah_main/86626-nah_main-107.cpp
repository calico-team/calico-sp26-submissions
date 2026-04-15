#include<cctype>
#include <iostream>
using namespace std;
int main() {
	int T, a[5] = { 0 }, b[10001] = { 0 };
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> a[1] >> a[2] >> a[3] >> a[4];
		for (int j = 0;j < a[1];j++) {
			cin >> b[j];

		}
		for (int j = 0;j < a[1];j++) {
			a[2] -= b[j];
			
			if (j % a[4] == 0 && j != 0) {
				
				
				a[2] += a[3];

			}
			if (a[2] < 0) {
					cout << "nah i'd lose" << endl;
					j = a[1]+1;
					break;
				}
		}if (a[2] >= 0) {
					cout << "nah i'd win" << endl;
		}


	}
	return 0;
}