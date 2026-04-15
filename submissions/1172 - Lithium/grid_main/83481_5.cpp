#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define endl '\n'
int t,n,a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3){
			sort(a+1,a+n+1);
			for(int i=1;i<=n;i++) cout<<a[(n+1)/2]<<' ';
			cout<<endl;
		}
	}
	return 0;
}