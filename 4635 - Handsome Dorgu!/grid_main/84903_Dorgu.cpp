#include <bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		long long b;
		cin>>b;
		for(long long j=0; j<b; j++){
			cin>>a[j];
		}
		for(long long j=0; j<b; j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
