#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int e[570][570];
bool tk[570][570][2];

void solve(){
    array<int,2>g,m;
    cin>>g[0]>>g[1]>>m[0]>>m[1];
    g[0]+=200,g[1]+=200,m[0]+=200,m[1]+=200;
    if(g>m)swap(g,m);

    for(int i=0;i<510;i++)for(int j=0;j<510;j++)e[i][j]=-1,tk[i][j][0]=tk[i][j][1]=false;
    
    int r=0;
    priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>>pq;
    pq.push({0,0,g[0],g[1]}),pq.push({0,1,m[0],m[1]});
    while(pq.size()){
        int t=pq.top()[0],ty=pq.top()[1],x=pq.top()[2],y=pq.top()[3];
        pq.pop();
        if(e[x][y]!=-1)continue;
        e[x][y]=ty,r+=ty;

        for(int di=0;di<4;di++){
            if(0<=x+dx[di]&&x+dx[di]<570){
                if(0<=y+dy[di]&&y+dy[di]<570){
                    if(abs(x+dx[di]-m[0])+abs(y+dy[di]-m[1])>570)continue;
                    if(e[x+dx[di]][y+dy[di]]==-1&&!tk[x+dx[di]][y+dy[di]][ty]){
                        tk[x+dx[di]][y+dy[di]][ty]=true;
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