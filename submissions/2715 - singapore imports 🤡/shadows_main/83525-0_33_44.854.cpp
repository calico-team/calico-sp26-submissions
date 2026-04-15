#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int T;
	cin>>T;
	for(int _=0;_<T;_++){
		int N;
		cin>>N;
		int MAXG=N*N*N,MING=0;
		// Face 1
		vector<int> B,W;
		for(int i=0;i<N;i++){
			string s;cin>>s;
			int b=0,w=0;
			for(char c:s){
				if(c=='#'){b++;}
				else{w++;}
			}
			B.push_back(b);
			W.push_back(w);
		}
		
		for(int i=0;i<N;i++){
			string s;cin>>s;
			int b=0,w=0;
			for(char c:s){
				if(c=='#'){b++;}
				else{w++;}
			}
			MING+=max(b,B[i]);
			MAXG-= (w*N+W[i]*N-w*W[i]);
		}
		cout<<MAXG<<' '<<MING<<endl;
	}
	return 0;
}
