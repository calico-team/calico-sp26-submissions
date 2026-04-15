#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				a[i][j]=(i+2*j)%5;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}