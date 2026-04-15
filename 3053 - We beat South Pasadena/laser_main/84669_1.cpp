#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+7;
int ans=INT_MAX;
int n,N,M,p,q;
vector<pair<int,int>>a;
signed main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n>>N>>M>>q>>p;
        for(int i=1;i<=n;i++){
            int x,y;cin>>x>>y;
            a.push_back({x,y});
        }
        pair<int,int>now=a[0];
        while(1){
            now.first+=p;
            now.second+=q;
            for(int i=0;i<n;i++){
                if(a[i]==now){
                    cout<<i<<endl;
                    goto end;
                }
            }
        }
        end:;
    }
    return 0;
}