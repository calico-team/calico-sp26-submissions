#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
int ans=INT_MAX;
signed main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
        int n,N,M,p,q;
        cin>>n>>N>>M>>q>>p;
        vector<pair<int,int>>a(n+1);
        for(int i=1;i<=n;i++){
            int x,y;cin>>x>>y;
            a[i]={x,y};
        }
        pair<int,int>now=a[1];
        while(1){
            now.first+=p;
            now.second+=q;
            if(now.first>N) now.first-=N;
            if(now.second>M) now.second-=M;
            bool flag=0;
            for(int i=1;i<=n;i++){
                if(a[i]==now){
                    cout<<i-1<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        a.clear();
    }
    return 0;
}