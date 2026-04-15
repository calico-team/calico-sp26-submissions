#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,m,p,q,x[100001],y[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>k>>n>>m>>p>>q;
		for(int i=1;i<=k;i++){
			cin>>x[i]>>y[i];
		}
		long double ans=1000000000000000000;ll jans=1;
		for(int i=2;i<=k;i++){
			x[i]=(x[i]-x[1]+n)%n;y[i]=(y[i]-y[1]+m)%m;
			long double bb=1.0*y[i]/p+1.0*x[i]/q;
			if(1.0*n*n*p/(1.0*m*q*q)-1.0*m/p!=0)bb/=1.0*n*n*p/(1.0*m*q*q)-1.0*m/p;
			long double a;
			if(1.0*n*n*p/(1.0*m*q*q)-1.0*m/p==0)a=y[i]/p;
			else a=1.0*(y[i]+1.0*m*bb)/p;
			if(a>0&&a<ans){
				ans=a;
				jans=i;
			}
			//x[i]-=x[0],y[i]-=y[0]
			//a*q=x[i]+n*aa,a*p=y[i]+m*bb
			//(x[i]+n*aa)/q=(y[i]+m*bb)/p
			//n*bb*np/mq/q=m*bb/p+(y[i]/p-x[i]/q)
			//aa=(np/mq)*bb
			//bb(n*np/mq/q-m/p)=(y[i]/p-x[i]/q)
			//bb=(y[i]/p-x[i]/q)/(n*np/mq/q-m/p)
			//a=(y[i]+m*bb)/p
		}
		cout<<jans-1<<endl;
	}
	return 0;
}
