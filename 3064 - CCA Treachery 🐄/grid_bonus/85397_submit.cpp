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
        int err1 = 0;
        FOR(i, 1, n)
            err1 += abs(top[i] - top[i-1]);
        vector<int> copy = top;
        sort(copy.begin(), copy.end());
        int ans = copy[n/2];
        int err2 = 0;
        FOR(i, 0, n)
            err2 += abs(copy[i] - ans);

        if(err2 < err1){
            FOR(i, 0, n)
                cout << ans << " ";
            cout << endl;
        }
        else{
            print(top);
        }
    }
}