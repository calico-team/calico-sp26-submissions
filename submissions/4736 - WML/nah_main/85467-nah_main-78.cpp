#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	vector<string>ans;
	for(int i = 0;i<t;i++){
		int n,p,r,k;
		cin>>n>>p>>r>>k;
		vector<int>a(n);
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		int k_tmp = 0;
		bool f = true;
		for(int i = 0;i<n;i++){
			if(k_tmp == k){
				p+=r;
				k_tmp = 0;
			}
			p-=a[i];
			if(p<0){
				f = false;
				ans.push_back("nah i��d lose");
				break;
			}
			k_tmp+=1;
		}
		if(f){
			ans.push_back("nah i��d win");
		}
	}
	for(int i = 0;i<t;i++){
		cout<<ans[i]<<endl;
	}
}
