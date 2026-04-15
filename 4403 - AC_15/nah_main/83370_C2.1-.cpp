#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,p,r,k;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>p>>r>>k;
		int e[t+2];
		for(int j=0;j<n;j++){
			cin>>e[j];
		}
		int dylan_power=p;
		bool win=1;
		for(int j=0;j<n;j++){
			dylan_power-=e[j];
			if(dylan_power<0){
				win=0;
				break;
			}
			if((j+1)%k==0){
				dylan_power+=r;
			}
		}
		if(win){
			cout<<"nahi'dwin"<<endl;
		}else{
			cout<<"nahi'dlose"<<endl;
		}
	}
	return 0;
}
//57 65 97
