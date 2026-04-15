#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int a[200000];
	int b[200000];
	while(t--){
		int x=0;
		cin>>x;
		for(int i=0;i<x;i++){
			cin>>a[i];
		}
		b[0]=a[0];
		for(int i=1;i<x-1;i++){
			int maxx=max(b[i-1],a[i]);
			int minn=min(b[i-1],a[i]);
			if(a[i+1]>maxx)b[i]=maxx;
			else if(a[i+1]<minn)b[i]=minn;
			else b[i]=a[i+1];
		}
		b[x-1]=a[x-1];
		for(int i=0;i<x;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}