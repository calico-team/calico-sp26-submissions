#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int k,n,m,dx,dy;
    cin>>k>>n>>m>>dy>>dx;
    array<int,2>p;

    vector<vector<int>>b(n+1,vector<int>(m+1,-1));

    cin>>p[0]>>p[1],b[p[0]][p[1]]=0;
    for(int i=1,x,y;i<k;i++)cin>>x>>y,b[x][y]=i;

    p[0]+=dx,p[1]+=dy;
    p[0]%=n,p[1]%=m;
        // cout<<p[0]<<" ~ "<<p[1]<<endl;
    while(b[p[0]][p[1]]==-1){
        // cout<<p[0]<<" ~ "<<p[1]<<endl;
        p[0]+=dx,p[1]+=dy;
        p[0]%=n,p[1]%=m;
    }
    cout<<b[p[0]][p[1]]<<'\n';
}

main(){
    int t;
    cin>>t;
    while(t--)solve();
}

/*
4
3 10 10 1 1
0 0
2 2
9 9
3 6 8 2 1
1 1
1 5
5 1
3 6 8 2 1
1 1
2 3
4 4
3 5 5 2 3
2 2
0 0
1 4
*/