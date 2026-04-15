#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N_=4005,M_=2000005;
int n,m,d,R[M_],C[M_],W[M_],ord[M_];
ll V[M_],a[N_];
double e[M_];
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m>>d;
for(int i=1;i<=m;i++)cin>>R[i]>>C[i]>>V[i]>>W[i];
for(int i=1;i<=n;i++)a[i]=1;
for(int it=0;it<5;it++){
for(int i=1;i<=m;i++){
int r=R[i],c=C[i];
ll cur=a[r]*a[c];
if(cur==V[i])continue;
if(rand()&1){
ll t=(ll)sqrt((double)V[i]*a[r]/a[c]);
if(t<1)t=1;
if(t>1000000000)t=1000000000;
a[r]=t;
}else{
ll t=(ll)sqrt((double)V[i]*a[c]/a[r]);
if(t<1)t=1;
if(t>1000000000)t=1000000000;
a[c]=t;
}
}
}
for(int i=1;i<=m;i++){
ll cur=a[R[i]]*a[C[i]];
e[i]=W[i]*fabs(cur-V[i])/V[i];
ord[i]=i;
}
sort(ord+1,ord+m+1,[](int x,int y){return e[x]>e[y];});
int k=min(d,m);
for(int i=1;i<=n;i++){
if(i>1)cout<<' ';
cout<<a[i];
}
cout<<endl;
cout<<k;
for(int i=1;i<=k;i++)cout<<' '<<ord[i];
cout<<endl;
return 0;
}