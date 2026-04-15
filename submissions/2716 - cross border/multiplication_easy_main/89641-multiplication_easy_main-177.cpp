#include<bits/stdc++.h>

using namespace std;



const int mn=4005;
const int mm=2000005;
int r[mm],c[mm],v[mm],w[mm];
vector<int> g[mn];
long long a[mn];
struct nd{
long long vl;
double wt;
bool operator<(const nd& ot) const{
return vl<ot.vl;
}
};
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int n,m,d;
if(!(cin>>n>>m>>d)) return 0;
for(int x=1;x<=m;x++){
cin>>r[x]>>c[x]>>v[x]>>w[x];
g[r[x]].push_back(x);
g[c[x]].push_back(x);
}
for(int y=1;y<=n;y++) a[y]=1;
for(int s=1;s<=20;s++){
for(int y=1;y<=n;y++){
vector<nd> vc;
double tt=0;
for(int id:g[y]){
int o=(r[id]==y)?c[id]:r[id];
long long tg=max(1LL,(long long)round((double)v[id]/a[o]));
double tw=(double)w[id]*a[o]/v[id];
vc.push_back({tg,tw});
tt+=tw;
}
if(vc.empty()) continue;
sort(vc.begin(),vc.end());
double cr=0;
for(auto& p:vc){
cr+=p.wt;
if(cr>=tt/2.0){
a[y]=p.vl;
break;
}
}
if(a[y]<1) a[y]=1;
if(a[y]>1e9) a[y]=1e9;
}
}
vector<pair<double,int>> pn;
for(int x=1;x<=m;x++){
double p=(double)w[x]*abs(a[r[x]]*a[c[x]]-v[x])/v[x];
pn.push_back({p,x});
}
sort(pn.begin(),pn.end());
vector<int> ds;
for(int x=0;x<d;x++){
ds.push_back(pn[m-1-x].second);
}
for(int y=1;y<=n;y++){
cout<<a[y]<<(y==n?"":" ");
}
cout<<"\n";
cout<<ds.size();
for(int id:ds){
cout<<" "<<id;
}
cout<<"\n";
return 0;
}