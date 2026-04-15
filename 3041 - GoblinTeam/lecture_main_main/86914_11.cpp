#include<bits/stdc++.h>
using namespace std;
void read_your_input(){
int t;cin>>t;
while(t--){
int n,m,k;cin>>n>>m>>k;
vector<string>g(n);
for(int i=0;i<n;i++)cin>>g[i];
vector<pair<int,int>>av;
for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]=='-')av.push_back({i,j});
int p=av.size();
int um=n+m-2,vm=n+m-1;
vector<vector<int>>cnt(um+1,vector<int>(vm+1,0));
for(auto[x,y]:av){
int u=x+y,v=x-y+m;
cnt[u][v]++;
}
for(int i=0;i<=um;i++)for(int j=0;j<=vm;j++){
if(i>0)cnt[i][j]+=cnt[i-1][j];
if(j>0)cnt[i][j]+=cnt[i][j-1];
if(i>0&&j>0)cnt[i][j]-=cnt[i-1][j-1];
}
auto chk=[&](int d){
for(int u=0;u+d<=um;u++)for(int v=0;v+d<=vm;v++){
int u2=u+d,v2=v+d;
int sum=cnt[u2][v2];
if(u>0)sum-=cnt[u-1][v2];
if(v>0)sum-=cnt[u2][v-1];
if(u>0&&v>0)sum+=cnt[u-1][v-1];
if(sum>=k)return true;
}
return false;
};
int l=0,r=um,ans=r;
while(l<=r){
int mid=(l+r)/2;
if(chk(mid))ans=mid,r=mid-1;
else l=mid+1;
}
int d=ans;
for(int u=0;u+d<=um;u++)for(int v=0;v+d<=vm;v++){
int u2=u+d,v2=v+d;
int sum=cnt[u2][v2];
if(u>0)sum-=cnt[u-1][v2];
if(v>0)sum-=cnt[u2][v-1];
if(u>0&&v>0)sum+=cnt[u-1][v-1];
if(sum>=k){
vector<pair<int,int>>res;
for(auto[x,y]:av){
int uu=x+y,vv=x-y+m;
if(uu>=u&&uu<=u2&&vv>=v&&vv<=v2)res.push_back({x,y});
if(res.size()==k)break;
}
for(auto[x,y]:res)cout<<x<<" "<<y<<endl;
goto nxt;
}
}
nxt:;
}
}
int main(){read_your_input();}