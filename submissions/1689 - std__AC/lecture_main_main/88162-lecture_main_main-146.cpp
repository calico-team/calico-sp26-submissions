#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using lli=long long int;
using pii=pair<int, int>;
using plli=pair<lli, lli>;
using vlli=vector<lli>;
using vpii=vector<pii>;
using vplli=vector<plli>;
using vvi=vector<vi>;
using vvlli=vector<vlli>;
using vc=vector<char>;
using vvc=vector<vc>;
using vb=vector<bool>;
using vvb=vector<vector<bool>>;

vpii solve(int n, int m, vvb A, int k){
    vvi B(n+m, vi(n+m, 0));
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j) B[i+j][i-j+m]=A[i][j];
    }
    ++k;
    vvi pre(n+m+1, vi(n+m+1, 0));
    for (int i=0; i<n+m; ++i){
        for (int j=0; j<n+m; ++j) pre[i+1][j+1]+=B[i][j];
    }
    for (int i=1; i<=n+m; ++i){
        for (int j=1; j<=n+m; ++j) pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
    }
    int mx=-1;
    pii best={-1, -1};
    for (int i=0; i+k<=n+m; ++i){
        for (int j=0; j+k<=n+m; ++j){
            int v=pre[i+k][j+k]-pre[i][j+k]-pre[i+k][j]+pre[i][j];
            if (v>mx) mx=v, best={i, j};
        }
    }
    vpii ret;
    for (int i=best.first; i<best.first+k; ++i){
        for (int j=best.second; j<best.second+k; ++j){
            if (B[i][j]) ret.push_back({(i+j-m)/2, (i-j+m)/2});
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--){
        int n, m, k;
        cin >> n >> m >> k;
        vvb A(n, vb(m));
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                char c;
                cin >> c;
                A[i][j]=(c=='-');
            }
        }
        int low=0;
        int high=n+m;
        while (low!=high){
            int mid=(low+high)/2;
            if (solve(n, m, A, mid).size()>=k) high=mid;
            else low=mid+1;
        }
        vpii ans=solve(n, m, A, low);
        for (int i=0; i<k; ++i) cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}