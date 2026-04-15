#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int n,m;
		cin>>n>>m;
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				a[j][k]=(2*j+k)%5;
			}
		}
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				cout<<a[j][k]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
} 
