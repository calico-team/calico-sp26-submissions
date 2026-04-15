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
        string a, b; cin >> a >> b;
        string ans;
        int num = 0;
        for(auto& i : a){
            if(i == b[num]){
                ++num;
                ans += i;
            }
            else{
                ans += '#';
            }
        }
        cout << ans << endl;
    }
}