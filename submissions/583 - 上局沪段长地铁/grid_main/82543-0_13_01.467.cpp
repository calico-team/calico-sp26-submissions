#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100001],b[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		b[1]=a[1];b[n]=a[n];
		for(int i=2;i<n;i++){
			if(a[i]>=a[i-1]&&a[i]<=a[i+1])b[i]=a[i];
			else if(a[i]<=a[i-1]&&a[i]>=a[i+1])b[i]=a[i];
			else b[i]=a[i+1];
		}
		for(int i=1;i<=n;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
