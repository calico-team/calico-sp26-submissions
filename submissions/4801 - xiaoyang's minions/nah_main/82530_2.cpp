#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,p,r,k;
	cin>>n>>p>>r>>k;
	int arr[n];
	for(int i=0; i<n; i++)cin>>arr[i];
	int cnt=0;
	int curr=p;
	for(int i=0; i<n; i++){
		while(curr < arr[i] and cnt > 0){
			curr += r;
			cnt--;
		}
		if(curr < arr[i]){
			cout << "nah i'd lose\n";
			return;
		}
		curr -= arr[i];
		if((i+1)%k==0){
			cnt++;
		}
	}
	cout << "nah i'd win\n";
	return;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)solve();
}
