#include <bits/stdc++.h>
using namespace std;

int main(){
	string a;
	string b;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int cur = 0;
		string res = "";
		for(int j=0;j<a.length();j++){
			if(a[j]==b[cur]){
				res+=b[cur];
				cur++;
			}else{
				res+="#";
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
