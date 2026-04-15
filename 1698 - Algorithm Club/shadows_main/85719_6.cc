#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; 
    cin >> t;
    
    while(t--) {
        int n; 
        cin >> n;
        ll r1[n] = {}, r2[n] = {};
        
        for(int i = 0; i < n; ++i) {
            string s; 
            cin >> s;
            for(char c : s) {
                if(c == '#') r1[i]++;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            string s; 
            cin >> s;
            for(char c : s) {
                if(c == '#') r2[i]++;
            }
        }
        
        long long mx = 0, mn = 0;
        for(int i = 0; i < n; ++i) {
            mx += r1[i] * r2[i];
            mn += max(r1[i], r2[i]);
        }
        
        cout << mx << " " << mn << "\n";
    }
    return 0;
}