#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        string s1; cin >> s1;
        if(s==s1){cout << s << endl; continue;}
        int cur = 0;
        char next = s1[0];
        bool good = true;
        for(auto &i: s) {
            if(i == next && good) {
                cur++;
                if(cur == s1.length()) good=false;
                else next = s1[cur];
            }
            else i='#';
        }
        cout << s << endl;
    }
}
