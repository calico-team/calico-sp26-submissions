#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,p,r,k;
    cin>>n>>p>>r>>k;
    int u=0;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];

    for(int i=1;i<=n;i++){
        if(u>=k)p+=r,u=0;
        p-=v[i],u++;
        if(p<0)return cout<<"nah i'd lose\n",void();
    }
    cout<<"nah i'd win\n";
}

main(){
    int t;
    cin>>t;
    while(t--)solve();
}