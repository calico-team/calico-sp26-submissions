#include <bits/stdc++.h>
using namespace std;
long long x[100005],y[100005];
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		long long a;
		cin>>a;
		for(long long j=0; j<a;j++){
			cin>>x[i];
			y[i]=x[i];
		}
		sort(y,y+a);
		long long dorgu=y[n/2];
		for(long long j=0; j<a;j++){
			cout<<dorgu<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
