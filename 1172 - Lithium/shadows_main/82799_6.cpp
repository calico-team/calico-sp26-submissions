#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define endl '\n'
int n,t;
string s1[1005],s2[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s1[i];
		for(int i=1;i<=n;i++) cin>>s2[i];
		int minn=0,maxx=0;
		for(int i=1;i<=n;i++){
			int cnt1=0,cnt2=0;
			for(int j=0;j<n;j++) cnt1+=(s1[i][j]=='#');
			for(int j=0;j<n;j++) cnt2+=(s2[i][j]=='#');
			minn+=max(cnt1,cnt2);
			maxx+=cnt1*cnt2;
		}
		cout<<maxx<<' '<<minn<<endl;
	}
	return 0;
}