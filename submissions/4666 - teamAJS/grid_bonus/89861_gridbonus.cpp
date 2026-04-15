#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> solve(int n,vector<int>& a){
    set<int> s(a.begin(),a.end());
    vector<int> v(s.begin(),s.end());
    int k=v.size();
    vector<int> dp(k);
    vector<vector<int>> p(n,vector<int>(k));
    for(int j=0;j<k;j++)dp[j]=abs(a[0]-v[j]);
    for(int i=1;i<n;i++){
        vector<int> ndp(k);
        int b=2e18,bi=-1;
        for(int j=0;j<k;j++){
            if(dp[j]-v[j]<b){b=dp[j]-v[j];bi=j;}
            p[i][j]=bi;
            ndp[j]=v[j]+b;
        }
        b=2e18;bi=-1;
        for(int j=k-1;j>=0;j--){
            if(dp[j]+v[j]<b){b=dp[j]+v[j];bi=j;}
            if(b-v[j]<ndp[j]){ndp[j]=b-v[j];p[i][j]=bi;}
        }
        for(int j=0;j<k;j++)dp[j]=ndp[j]+abs(a[i]-v[j]);
    }
    vector<int> r(n);
    int c=0;
    for(int j=1;j<k;j++)if(dp[j]<dp[c])c=j;
    for(int i=n-1;i>=0;i--){
        r[i]=v[c];
        if(i>0)c=p[i][c];
    }
    return r;
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)cin>>A[i];
        vector<int> res=solve(N,A);
        for(int i=0;i<N;i++)cout<<res[i]<<(i==N-1?"":" ");
        cout<<'\n';
    }
    return 0;
}
