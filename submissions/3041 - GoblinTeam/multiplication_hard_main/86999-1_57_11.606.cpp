#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct E{int r,c;ll v;int w;};
int main(){
ios::sync_with_stdio(0);cin.tie(0);
int n,m,d;cin>>n>>m>>d;
vector<E>e(m);
vector<vector<int>>adj(n);
for(int i=0;i<m;i++){
cin>>e[i].r>>e[i].c>>e[i].v>>e[i].w;
e[i].r--;e[i].c--;
adj[e[i].r].push_back(i);
adj[e[i].c].push_back(i);
}
vector<ll>a(n,1);
vector<int>disc;
vector<bool>bad(m,0);
auto upd=[&](int i){
vector<pair<ld,ld>>t;
ld sw=0;
for(int id:adj[i]){
if(bad[id])continue;
E&ed=e[id];
int j=(ed.r==i?ed.c:ed.r);
ld tv=(ld)ed.v/a[j];
ld wt=(ld)ed.w*a[j]/ed.v;
t.push_back({tv,wt});
sw+=wt;
}
if(t.empty())return;
sort(t.begin(),t.end());
ld cur=0,h=sw/2;
ld med=t[0].first;
for(auto&p:t){
cur+=p.second;
if(cur>=h){med=p.first;break;}
}
a[i]=(ll)round(med);
if(a[i]<1)a[i]=1;
if(a[i]>1000000000)a[i]=1000000000;
};
for(int it=0;it<5;it++){
for(int i=0;i<n;i++)upd(i);
}
vector<pair<ld,int>>err(m);
for(int i=0;i<m;i++){
ld er=(ld)e[i].w*fabsl((ld)a[e[i].r]*a[e[i].c]-e[i].v)/e[i].v;
err[i]={er,i};
}
sort(err.begin(),err.end(),[&](auto&x,auto&y){return x.first>y.first;});
int cnt=min(d,m);
for(int i=0;i<cnt;i++){
bad[err[i].second]=1;
disc.push_back(err[i].second+1);
}
for(int it=0;it<5;it++){
for(int i=0;i<n;i++)upd(i);
}
for(int i=0;i<n;i++){
cout<<a[i];
if(i<n-1)cout<<" ";
}
cout<<endl;
cout<<disc.size();
for(int x:disc)cout<<" "<<x;
cout<<endl;
return 0;
}