#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N_=4005,M_=2000005;
int n,m,d,R[M_],C[M_],W[M_],ord[M_],del[M_];
ll V[M_];
double a[N_],e[M_];
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m>>d;
for(int i=1;i<=m;i++)cin>>R[i]>>C[i]>>V[i]>>W[i];
for(int i=1;i<=n;i++)a[i]=pow(10.0,rand()/(RAND_MAX+1.0)*9.0);
int k=0;
for(int t=0;t<25;t++){
for(int i=1;i<=n;i++){
double s=0,sw=0;
for(int j=1;j<=m;j++){
if(del[j])continue;
if(R[j]==i){
double o=V[j]/a[C[j]];
double w=W[j];
s+=log(o)*w;
sw+=w;
}
if(C[j]==i){
double o=V[j]/a[R[j]];
double w=W[j];
s+=log(o)*w;
sw+=w;
}
}
if(sw>0){
double g=exp(s/sw);
if(g<1)g=1;
if(g>1e9)g=1e9;
a[i]=g;
}
}
if(t%5==4||t==24){
for(int j=1;j<=m;j++){
ll cur=(ll)(a[R[j]]*a[C[j]]+0.5);
e[j]=W[j]*fabs(cur-V[j])/V[j];
ord[j]=j;
}
sort(ord+1,ord+m+1,[](int x,int y){return e[x]>e[y];});
int nd=min(d,m);
for(int j=1;j<=m;j++)del[j]=0;
for(int j=1;j<=nd;j++)del[ord[j]]=1;
}
}
for(int i=1;i<=n;i++){
if(i>1)cout<<' ';
ll out=(ll)(a[i]+0.5);
if(out<1)out=1;
if(out>1000000000)out=1000000000;
cout<<out;
}
cout<<endl;
k=0;
for(int i=1;i<=m;i++)if(del[i])k++;
cout<<k;
for(int i=1;i<=m;i++)if(del[i])cout<<' '<<i;
cout<<endl;
return 0;
}