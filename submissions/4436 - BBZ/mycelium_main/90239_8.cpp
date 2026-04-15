#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=100;
int dist[N][N];
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};
void bfs(int b,int a,int d,int c){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j]=0;
        }
    }
    queue<pair<int,pair<int,int>>>q,q1;
    dist[b][a]=1;
    dist[d][c]=2;
    q.push({2,{b,a}});
    q1.push({7,{d,c}});
    int t=1;
    while(!q1.empty()){
        while(!q.empty() && q.front().first==t){
            auto [ui,uj]=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int vi=ui+dy[i];
                int vj=uj+dx[i];
                if(vi>=0 && vi<N && vj>=0 && vj<N){
                    if(dist[vi][vj]==0){
                        dist[vi][vj]=1;
                        q.push({t+2,{vi,vj}});
                    }
                }
            }
        }
        while(!q1.empty() && q1.front().first==t){
            auto [ui,uj]=q1.front().second;
            q1.pop();
            for(int i=0;i<4;i++){
                int vi=ui+dy[i];
                int vj=uj+dx[i];
                if(vi>=0 && vi<N && vj>=0 && vj<N){
                    if(dist[vi][vj]==0){
                        dist[vi][vj]=2;
                        q1.push({t+7,{vi,vj}});
                    }
                }
            }
        }
        t++;
    }
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        bfs(b+50,a+50,d+50,c+50);
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dist[i][j]==2) ans++;
            }
        }
        cout << ans << endl;
    }
}