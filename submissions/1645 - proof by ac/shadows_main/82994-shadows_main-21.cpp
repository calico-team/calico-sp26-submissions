#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin>>n;
        
        ll greater = 0;
        ll smaller = 0;

        vector<int> v1;

        for(int i = 0; i < n; i++){
            string s; cin>>s;
            int c = 0;
            for(auto j : s) if(j=='#')c++;
            v1.push_back(c);
        }
        for(int i = 0; i < n; i++){
            string s; cin>>s;
            int c = 0;
            for(auto j : s) if(j=='#')c++;
            greater += v1[i]*c;
            smaller += max(v1[i],c);
        }
        cout<<greater<<" "<<smaller<<nl;
        

    }

    return 0;
}