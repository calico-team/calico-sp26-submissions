#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int MOD = 998244353, N = 2e5+5;

int median(int a,int b,int c){

    
    vector<int> cur={a,b,c};
    sort(cur.begin(),cur.end());
    return cur[1];
    
}

void slave(){

    int n;
    cin>>n;
    vector<int> a(n);

    for(int &i:a) cin>>i;

    vector<int> dp=a;

    for(int i=1;i<n-1;++i){

        dp[i]=median(dp[i-1],dp[i],dp[i+1]);

    }

    for(int i=n-2;i>=1;--i){

        dp[i]=median(dp[i-1],dp[i],dp[i+1]);

    }    

    for(int &i:dp) cout<<i<<" ";
    cout<<endl;

        
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