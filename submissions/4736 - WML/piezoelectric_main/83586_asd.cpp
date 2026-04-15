#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	vector<int>a;
	for(int i = 0;i<t;i++){
		int l,w,e,r;
		cin>>l>>w>>e>>r;
		int tmp = e/((l+w)*2*r);
		a.push_back(tmp);
	}
	for(int i = 0;i<t;i++){
		cout<<a[i]<<endl;
	}
}
