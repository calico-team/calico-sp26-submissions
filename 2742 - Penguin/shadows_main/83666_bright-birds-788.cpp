// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        int n;
        cin >> n;
        vector<string> s1(n), s2(n);
        for (int i = 0; i < n; i++) cin >> s1[i];
        for (int i = 0; i < n; i++) cin >> s2[i];
        long long minans = 0, maxans = 0;
        for (int i = 0; i < n; i++){
            int c1 = 0, c2 = 0;
            for (int j = 0; j < n; j++) if (s1[i][j] == '#') c1++;
            for (int j = 0; j < n; j++) if (s2[i][j] == '#') c2++;
            minans += max(c1, c2);
            maxans += c1*c2;
        }
        cout << maxans << " " << minans << endl;
    }
}
