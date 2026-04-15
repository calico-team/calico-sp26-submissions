#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int T;
	cin>>T;
	for(int _=0;_<T;_++){
		string a,b;
		cin>>a>>b;
		string out;
		int j=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[j] or j==b.size()){
				out.push_back('#');
			}else{
				out.push_back(b[j]);
				j++;
			}
		}
		cout<<out<<endl;
	}
	return 0;
}
