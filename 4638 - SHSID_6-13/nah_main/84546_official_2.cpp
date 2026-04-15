#include<bits/stdc++.h> 
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,p,r,k,e[10010];
		cin>>n>>p>>r>>k;
		for(int i=1;i<=n;i++){
			cin>>e[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(p>=e[i]) cnt++;
			p-=e[i];
			if(cnt!=0&&cnt%k==0&&p<=0)
				p+=r;
			if(p<0){
				cout<<"nah i'd lose"<<endl;
				break;
			}
		}
		if(p>=0){
			cout<<"nah i'd win"<<endl;		
		}
	}
}
