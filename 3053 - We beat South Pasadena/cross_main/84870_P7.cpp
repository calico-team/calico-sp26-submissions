#include <iostream>
#include <queue>
int main(){
    using namespace std;
    //cout<<"check";
    int grid[1001][1001]={};
    bool vis[1001][1001]={};
    grid[1][1]=0; grid[1][2]=1; grid[2][1]=2; grid[0][1]=3; grid[1][0]=4;
    // 2 4 3 
    // 3 0 1 ->
    // 1 2 4
    //   |
    //  \./
    queue<pair<int,int> > q;
    q.push(make_pair(1,1));q.push(make_pair(1,2));q.push(make_pair(2,1));q.push(make_pair(0,1));q.push(make_pair(1,0));
    vis[1][1]=1; vis[1][2]=1; vis[2][1]=1; vis[0][1]=1; vis[1][0]=1;
    int dr[4]={-1,2,1,-2};
    int dc[4]={2,1,-2,-1};
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(r+dr[i]>=0 && r+dr[i]<1001 && c+dc[i]>=0 && c+dc[i]<1001 && !vis[r+dr[i]][c+dc[i]]){
                grid[r+dr[i]][c+dc[i]]=grid[r][c];
                vis[r+dr[i]][c+dc[i]]=1;
                q.push(make_pair(r+dr[i],c+dc[i]));
            }
        }
    }
    //for(int i=0;i<20;i++){
    //    for(int j=0;j<20;j++){
    //        cout<<grid[i][j]<<" ";
    //    }
    //    cout<<"\n";
    //}

    int n,m;
    int t=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    

}