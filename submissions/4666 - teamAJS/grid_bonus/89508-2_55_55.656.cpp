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
        int b=999999999999999;
        int bi=-1;
        for(int j=0;j<k;j++){
            int cur=dp[j]-v[j];
            if(cur<b){
                b=cur;
                bi=j;
            }
            p[i][j]=bi;
            ndp[j]=v[j]+b;
        }
        
        b=999999999999999;
        bi=-1;
        for(int j=k-1;j>=0;j--){
            int cur=dp[j]+v[j];
            if(cur<b){
                b=cur;
                bi=j;
            }
            if(b-v[j]<ndp[j]){
                ndp[j]=b-v[j];
                p[i][j]=bi;
            }
        }
        for(int j=0;j<k;j++)ndp[j]+=abs(a[i]-v[j]);
        dp=ndp;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
