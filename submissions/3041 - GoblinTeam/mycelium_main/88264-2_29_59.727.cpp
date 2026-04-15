#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll>> pii;
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
int main(){
ios::sync_with_stdio(false);cin.tie(0);
ll T;cin>>T;
while(T--){
ll xg,yg,xm,ym;cin>>xg>>yg>>xm>>ym;
ll D=abs(xg-xm)+abs(yg-ym);
ll md=(2*D+4)/5+2;
ll R=md+5;
unordered_map<ll,unordered_map<ll,ll>> mp;
priority_queue<pii,vector<pii>,greater<pii>> pq;
mp[xg][yg]=1;
mp[xm][ym]=2;
pq.push({0,{xg,yg}});
pq.push({0,{xm,ym}});
ll ans=1;
while(!pq.empty()){
auto tt=pq.top();pq.pop();
ll t=tt.first,x=tt.second.first,y=tt.second.second;
ll ty=mp[x][y];
if(ty==0)continue;
if(ty==2)ans++;
for(ll i=0;i<4;i++){
ll nx=x+dx[i],ny=y+dy[i];
if(abs(nx-xm)+abs(ny-ym)>R)continue;
if(mp[nx][ny]==0){
ll nt=t+(ty==1?2:7);
pq.push({nt,{nx,ny}});
mp[nx][ny]=ty;
}
}
}
cout<<ans<<endl;
}
return 0;
}