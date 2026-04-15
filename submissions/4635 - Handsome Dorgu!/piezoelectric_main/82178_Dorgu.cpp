#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int l,w,e,r;
		cin>>l>>w>>e>>r;
		int c=(l+w)*2;
		int cnt=e/r;
		int ans=cnt/c;
		cout<<ans<<endl;
	}
	
	return 0;
} 
