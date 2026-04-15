#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
    while(t--) {
        string s, v; cin >> s >> v;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < v.size() && v[j] == s[i]) ++j;
            else s[i] = '#';
        }
        cout << s << endl;
    }
}
