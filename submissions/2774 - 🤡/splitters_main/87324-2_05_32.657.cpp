#include<bits/stdc++.h>
#define int long long
using namespace std;

string temp[20];
string s[20];
int n,m;
pair<int,int>ans[20][20];
int cnt[20][20];
int vis[20][20];

pair<int,int>dir[4]={
    {1,0},{0,1},{-1,0},{0,-1}
};

char cant[4]={
    '^','<','v','>'
};

pair<int,int>add(pair<int,int>a,pair<int,int>b){
    return {a.first*b.second+b.first*a.second,a.second*b.second};
}

pair<int,int>simp(pair<int,int>a){
    int g=__gcd(a.first,a.second);
    a.first/=g;
    a.second/=g;
    return a;
}

void check(int x,int y){
    if(vis[x][y])return;
    vis[x][y]=1;
    if(s[x][y]=='<'){
        cnt[x][y-1]++;
        check(x,y-1);
    }else if(s[x][y]=='>'){
        cnt[x][y+1]++;
        check(x,y+1);
    }else if(s[x][y]=='^'){
        cnt[x-1][y]++;
        check(x-1,y);
    }else if(s[x][y]=='v'){
        cnt[x+1][y]++;
        check(x+1,y);
    }else if(s[x][y]=='S'){
        vector<pair<int,int>>can;
        for(int i=0;i<4;i++){
            int xx=x+dir[i].first;
            int yy=y+dir[i].second;
            if(s[xx][yy]!='.'&&s[xx][yy]!=cant[i]){
                can.push_back({xx,yy});
            }
        }
        int dv=can.size();
        if(dv){
            for(auto [xx,yy]:can){
                cnt[xx][yy]++;
                check(xx,yy);
            }
        }
    }
}

pair<int,int> bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({1,1});
    ans[1][1]=make_pair(1,1);
    pair<int,int>rans={0,1};
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        ans[x][y]=simp(ans[x][y]);
        //cerr<<x<<" "<<y<<":"<<ans[x][y].first<<" "<<ans[x][y].second<<"\n";
        if(x>n||y>m||x<=0||y<=0){
            rans=add(rans,ans[x][y]);
            continue;
        }
        if(s[x][y]=='<'){
            ans[x][y-1]=add(ans[x][y-1],ans[x][y]);
            cnt[x][y-1]--;
            if(cnt[x][y-1]==0)q.push({x,y-1});
        }else if(s[x][y]=='>'){
            ans[x][y+1]=add(ans[x][y+1],ans[x][y]);
            cnt[x][y+1]--;
            if(cnt[x][y+1]==0)q.push({x,y+1});
        }else if(s[x][y]=='^'){
            ans[x-1][y]=add(ans[x-1][y],ans[x][y]);
            cnt[x-1][y]--;
            if(cnt[x-1][y]==0)q.push({x-1,y});
        }else if(s[x][y]=='v'){
            ans[x+1][y]=add(ans[x+1][y],ans[x][y]);
            cnt[x+1][y]--;
            if(cnt[x+1][y]==0)q.push({x+1,y});
        }else if(s[x][y]=='X'){
            continue;
        }else if(s[x][y]=='S'){
            vector<pair<int,int>>can;
            for(int i=0;i<4;i++){
                int xx=x+dir[i].first;
                int yy=y+dir[i].second;
                if(s[xx][yy]!='.'&&s[xx][yy]!=cant[i]){
                    can.push_back({xx,yy});
                }
            }
            int dv=can.size();
            if(dv){
                auto sval=ans[x][y];
                sval.second*=dv;
                for(auto [xx,yy]:can){
                    ans[xx][yy]=add(ans[xx][yy],sval);
                    cnt[xx][yy]--;
                    if(cnt[xx][yy]==0)q.push({xx,yy});
                }
            }
        }
    }
    rans=simp(rans);
    return rans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>temp[i];
        }
        for(int i=0;i<=n+1;i++){
            s[i].clear();
            s[i].resize(m+1,'?');
        }
        for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++){
            cnt[i][j]=vis[i][j]=0;
            ans[i][j]={0,1};
            s[i][j]='?';
        }
        //cerr<<"work\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=temp[i-1][j-1];
            }
        }
        check(1,1);
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cerr<<cnt[i][j]<<" ";
            }
            cerr<<"\n";
        }*/
        auto ans=bfs(1,1);
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}