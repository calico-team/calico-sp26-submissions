#include <bits/stdc++.h>
#define DEBUG false
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

signed main() {
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    int t;
    cin>>t;
    while(t--){
        string s, s1;
        cin>>s1>>s;
        int i = 0;
        for(auto c : s1){
            if(c == s[i]){
                cout<<s[i];
                i++;
            }
            else{
                cout<<'#';
            }
        }
        cout<<endl;
    }
}