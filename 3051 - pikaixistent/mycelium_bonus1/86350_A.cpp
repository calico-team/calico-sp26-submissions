#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int vis[1500][1500];
int tc_id = 0;

void solve(){
    tc_id++;
    array<int,2>g,m;
    cin>>g[0]>>g[1]>>m[0]>>m[1];
    g[0]+=600,g[1]+=600,m[0]+=600,m[1]+=600;
    int r=0;
    priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>>pq;
    pq.push({0,0,g[0],g[1]}),pq.push({0,1,m[0],m[1]});
    while(pq.size()){
        int t=pq.top()[0],ty=pq.top()[1],x=pq.top()[2],y=pq.top()[3];
        pq.pop();
        if(vis[x][y]==tc_id)continue;
        vis[x][y]=tc_id,r+=ty;

        for(int di=0;di<4;di++){
            if(0<=x+dx[di]&&x+dx[di]<1500){
                if(0<=y+dy[di]&&y+dy[di]<1500){
                    if(vis[x+dx[di]][y+dy[di]]!=tc_id){
                        pq.push({t+2+5*ty,ty,x+dx[di],y+dy[di]});
                    }
                }
            }
        }
    }
    cout<<r<<'\n';
}
main(){
    int t;
    cin>>t;
    while(t--)solve();
}