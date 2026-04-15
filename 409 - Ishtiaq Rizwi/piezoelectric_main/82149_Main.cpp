#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int MOD = 998244353, N = 2e5+5;

void slave(){

    int l,w,e,r;
    cin>>l>>w>>e>>r;
    
    int per=2*(l+w)*r;
    cout<<e/per<<endl;
        
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--){
        
        slave();
        
    }
    
}