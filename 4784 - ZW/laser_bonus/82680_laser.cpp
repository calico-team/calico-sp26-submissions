#include<bits/stdc++.h>
using namespace std;

long long a(long long b,long long c,long long &d,long long &e){
if(!c){d=1;e=0;return b;}
long long f=a(c,b%c,e,d);
e-=b/c*d;
return f;
}

long long b(long long c,long long d,long long e){
long long f,g;
long long h=a(c,d,f,g);
if(e%h)return -1;
long long i=d/h;
f=(f*(e/h)%i+i)%i;
return f;
}

long long c(long long d,long long e){
return d/__gcd(d,e)*e;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

int d;
cin>>d;

while(d--){

long long e,f,g,h,i;
cin>>e>>f>>g>>h>>i;

vector<long long>j(e),k(e);

for(int l=0;l<e;l++)cin>>j[l]>>k[l];

long long l=j[0],m=k[0];

long long n=LLONG_MAX,o=-1;

for(int p=0;p<e;p++){

long long q=(j[p]-l%f+f)%f;
long long r=(k[p]-m%g+g)%g;

long long s=b(i,f,q);
long long t=b(h,g,r);

if(s==-1||t==-1)continue;

long long u=f/__gcd(f,i);
long long v=g/__gcd(g,h);

long long w,x;
long long y=a(u,v,w,x);

if((t-s)%y)continue;

long long z=c(u,v);

long long aa=(s+(t-s)/y*w%(v/y)*u)%z;
if(aa<0)aa+=z;

if(aa==0)aa+=z;

if(aa<n){
n=aa;
o=p;
}

}

cout<<o<<"\n";
}
}
