#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)cin>>arr[i];
	if(n==1){
		cout<<arr[0]<<'\n';
		return;
	}
	else if(n==2){
		cout<<min(arr[0],arr[1])<<" "<<min(arr[0],arr[1])<<'\n';
		return;
	}
	else{
		sort(arr,arr+n);
		cout<<arr[1]<<" "<<arr[1]<<" "<<arr[1]<<'\n';
		return;
	}
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--)solve();
}

