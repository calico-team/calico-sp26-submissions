#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
void add(ll&n1,ll&d1,ll n2,ll d2){ll d=d1/gcd(d1,d2)*d2;ll n=n1*(d/d1)+n2*(d/d2);ll g=gcd(n,d);n1=n/g;d1=d/g;}
int N,M;
vector<string>g;
ll tn,td;
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int gd(char c){if(c=='^')return 0;if(c=='v')return 1;if(c=='<')return 2;return 3;}
void dfs(int r,int c,ll n,ll d){
if(g[r][c]=='X')return;
if(g[r][c]=='.')return;
if(g[r][c]=='S'){
vector<pair<int,int>>v;
for(int i=0;i<4;i++){
int nr=r+dr[i],nc=c+dc[i];
if(nr<0||nr>=N||nc<0||nc>=M)continue;
if(g[nr][nc]=='.')continue;
if(g[nr][nc]=='X'){v.push_back({nr,nc});continue;}
int dir=gd(g[nr][nc]);
int br=nr+dr[dir],bc=nc+dc[dir];
if(br==r&&bc==c)continue;
v.push_back({nr,nc});
}
int k=v.size();
for(auto&p:v){
int nr=p.first,nc=p.second;
if(g[nr][nc]=='X')continue;
ll nn=n,nd=d*k;
ll g=gcd(nn,nd);
nn/=g;nd/=g;
dfs(nr,nc,nn,nd);
}
return;
}
int dir=gd(g[r][c]);
int nr=r+dr[dir],nc=c+dc[dir];
if(nr<0||nr>=N||nc<0||nc>=M){add(tn,td,n,d);return;}
if(g[nr][nc]=='.')return;
dfs(nr,nc,n,d);
}
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int T;
cin>>T;
while(T--){
cin>>N>>M;
g.resize(N);
for(int i=0;i<N;i++)cin>>g[i];
tn=0;td=1;
dfs(0,0,1,1);
cout<<tn<<" "<<td<<endl;
}
return 0;
}