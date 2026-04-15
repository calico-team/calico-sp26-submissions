#include <iostream>
using namespace std;
int l[110],w[110],e[100010],r[20],p[20];
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>l[i]>>w[i]>>e[i]>>r[i];
	}
	for(int i=1;i<=t;i++){
		int ans=0;
		p[i]=2*(l[i]+w[i]);
		ans=e[i]/(p[i]*r[i]);
		cout<<ans<<endl;
	}
	return 0; 
}
