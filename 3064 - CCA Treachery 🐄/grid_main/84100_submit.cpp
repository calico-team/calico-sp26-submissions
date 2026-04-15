#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define print(x) for(auto i : x) {cout << i << " ";} cout << endl;
#define cinVec(x) for(auto& i : x) cin >> i;
#define printB cout<<"⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯\n";

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> top(n); cinVec(top);
        bool inc = true;
        bool dec = true;
        FOR(i, 1, n){
            if(top[i]-top[i-1] < 0)
                inc = false;
            else if (top[i]-top[i-1] > 0)
                dec = false;
            if(!inc && !dec)
                break;
        }

        if(inc || dec){
            print(top);
        }
        else {
            //use only one number?
            sort(top.begin(), top.end());
            int ans = top[n/2];
            FOR(i, 0, n){
                cout << ans << " ";
            }
            cout << endl;
        }
    }
}