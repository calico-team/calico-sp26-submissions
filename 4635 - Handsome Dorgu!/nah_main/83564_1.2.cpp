#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	for (int i=0;i<a;i++){
		long long b,c,d,e;
		cin>>b>>c>>d>>e;
		long long f[b];
		long long sum=0;
		for (int j=0;j<b;j++){
			cin>>f[j];
			sum+=f[j];
		}
		long long cnt=1;
		for (int j=0;j<b;j++){
			c-=f[j];
			if (c<0){
				cnt=0;
				break;
			}
			if ((j+1)%e==0){
				c+=d;
			}
		}
		if (cnt==0){
			cout<<"nah i'd lose"<<endl;
		}
		else{
			cout<<"nah i'd win"<<endl;
		}
	}
}