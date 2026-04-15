#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int cnt=0;
		string a,b;
		cin>>a>>b;
		for(int j=0; j<a.length(); j++){
			if(cnt<b.length() && a[j]==b[cnt]) cnt++; 
			else a[j]='#';
		}
		for(int j=0; j<a.length(); j++){
			cout<<a[j];
		}
		cout<<endl;
	}
	
	return 0;
} 
