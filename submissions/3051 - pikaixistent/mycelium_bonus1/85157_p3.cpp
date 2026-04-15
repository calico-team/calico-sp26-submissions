#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int e[610][610];

void solve(){
    array<int,2>g,m;
    cin>>g[0]>>g[1]>>m[0]>>m[1];
    g[0]+=200,g[1]+=200,m[0]+=200,m[1]+=200;
    if(g>m)swap(g,m);

    for(int i=0;i<610;i++)for(int j=0;j<610;j++)e[i][j]=-1;
    
    int r=0;
    priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>>pq;
    pq.push({0,0,g[0],g[1]}),pq.push({0,1,m[0],m[1]});
    while(pq.size()){
        int t=pq.top()[0],ty=pq.top()[1],x=pq.top()[2],y=pq.top()[3];
        pq.pop();
        if(e[x][y]!=-1)continue;
        e[x][y]=ty,r+=ty;

        for(int di=0;di<4;di++){
            if(0<=x+dx[di]&&x+dx[di]<610){
                if(0<=y+dy[di]&&y+dy[di]<610){
                    if(e[x+dx[di]][y+dy[di]]==-1){
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