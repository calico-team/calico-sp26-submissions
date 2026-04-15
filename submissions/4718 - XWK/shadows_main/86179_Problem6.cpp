#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n; cin>>n;
    vector<string> a(n),b(n);
    vector<int> cnt,cnt2;
    for (auto &i:a) cin>>i;
    for (auto &i:b) cin>>i;
    int mx=(n*n*n),mn=0;
    for (auto i:a) {
        int c=0;
        for (auto j:i) {
            if (j=='.') {
                mx-=n;
                c++;
            }
            else mn++;
        }
        cnt.push_back(c);
        cnt2.push_back(n-c);
    }
    for (int i=0;i<n;i++) {
        for (auto j:b[i]) {
            if (j=='.') {
                mx-=n;
                mx+=cnt[i];
            }
            else mn++;
        }
    }
    cout<<mx<<" ";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (b[j][i]=='#' && cnt2[j]>0) {
                cnt2[j]--;
                mn--;
            }
        }
    }
    cout<<mn<<"\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in","r",stdin);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}