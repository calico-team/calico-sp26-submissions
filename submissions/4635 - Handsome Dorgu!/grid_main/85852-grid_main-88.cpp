#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	for (int i=0;i<a;i++){
		int b;
		cin>>b;
		int c[b];
		for (int j=0;j<b;j++){
			cin>>c[j];
		}
		for (int j=0;j<b;j++){
			cout<<c[j]<<" ";
		}
		cout<<endl;
	}
}