#include <iostream>
#include <queue>
int main(){
    using namespace std;
    int t=0;
    cin>>t;
    int xg,yg,xm,ym;
    while(t--){
        
        short grid[2001][2001]={};
        cin>>xg>>yg>>xm>>ym;

        int cnt=0;
        queue<pair<int,int> > q;
        q.push(make_pair(xg,yg));
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        grid[xg+1000][yg+1000]=1;
        while(!q.empty()){
            int x=q.front().first+1000;
            int y=q.front().second+1000;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0 && x+dx[i]<2001 && y+dy[i]>=0 && y+dy[i]<2001 && grid[x+dx[i]][y+dy[i]]==0 && (grid[x][y])*2<=(abs(x+dx[i]-xm-1000)+abs(y+dy[i]-ym-1000))*7){
                    grid[x+dx[i]][y+dy[i]]=grid[x][y]+1;
                    q.push(make_pair(x+dx[i]-1000,y+dy[i]-1000));
                }
            }
        }
        for(int i=0;i<2001;i++){
            for(int j=0;j<2001;j++){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j]==0){
                    cnt+=1;
                }
            }
            //cout<<"\n";
        }
        cout<<cnt<<"\n";

    }
}