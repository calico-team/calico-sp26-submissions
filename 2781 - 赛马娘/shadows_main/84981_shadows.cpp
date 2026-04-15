#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    vector<string> s1;
    vector<string> s2;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s1.push_back(s);
    }

    int min = 0;
    int maxe = n * n * n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c1 = 0, c2 = 0;
        int d1 = 0, d2 = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') c2++;
            if (s1[i][j] == '#') c1++;
        }
        min += max(c1, c2);

        d1 = n - c1;
        d2 = n - c2;

        maxe -= (d1 * n + d2 * n - d1 * d2);
    }

    cout << maxe << " " << min << "\n";
    return 0;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
        cin >> n;
	    solve(n);
	}
}
