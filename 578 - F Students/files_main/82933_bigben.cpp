#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
5
ccaalliiccoo
calico
big_bens_bday
bbb
job
jb
include_over_californication
ilovecalico
six_seven_rizzler_sigma_banned_discord_skibidi_toilet
severance

*/


int main() {
	int t;
	cin >> t;
	for (int ab = 0; ab < t; ab++) {
		string a, b;
		cin >> a >> b;
		int i = 0;
		int j = 0;
		vector<int> remove;
		while (i < a.size()) {
			if (j < b.size() && a[i] == b[j]) {
				j++;
			}
			else {
				remove.push_back(i);
			}
			i++;
		}
		string newa = a;
		for (int x = 0; x < remove.size(); x++) {
			newa[remove[x]] = '#';
		}
		cout << newa << endl;
	}
}