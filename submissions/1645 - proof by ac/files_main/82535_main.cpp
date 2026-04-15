#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin>>t;
    while(t--){
        string s,t; cin>>s>>t;

        int p = 0;
        for(auto i: t){
            while(i!=s[p]){
                p++;
                cout<<"#";
            }
            cout<<i;
            p++;
        }
        while(p<s.length()) {
            cout<<"#";
            p++;
        }
        cout<<nl;
    }

    return 0;
}