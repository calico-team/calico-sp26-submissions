#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	cin>>a;
	for (int i=0;i<a;i++){
		long long b,c,d,e,f;
		cin>>b>>c>>d>>e>>f;
		long long g[b][2];
		for (int j=0;j<b;j++){
			cin>>g[j][0]>>g[j][1];
		}
		long long xa=g[0][0],xb=g[0][1];
		long long flag=0;
		while(flag==0){
			xa=(xa+f)%c;
			xb=(xb+e)%d;
			flag=0;
			for (int j=0;j<b;j++){
				if (xa==g[j][0] and xb==g[j][1]){
					cout<<j<<endl;
					flag=1;
					break;
				}
			}
		}
	}
}