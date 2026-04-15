#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e5+10;
const int mod=998244353;
const int P=1e9+7;

void solve(){
    int n,p,r,k;cin>>n>>p>>r>>k;
    vector<int> a(n+1);
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        if(cnt1%k==0&&cnt1>0) cnt2++;
        if(p>=a[i]) p-=a[i],cnt1++;
        else if(cnt2>=(a[i]-p+r-1)/r) cnt2-=(a[i]-p+r-1)/r,p+=((a[i]-p+r-1)/r)*r;
        else {
            cout<<"nah i'd lose"<<endl;return ;
        }
    }
    cout<<"nah i'd win"<<endl;
}   

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    cin>>tc;
    while(tc--) solve();
}