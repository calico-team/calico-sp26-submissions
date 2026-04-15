#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	cin>>a;
	for (int i=0;i<a;i++){
		long long b;
		cin>>b;
		char c[b][b];
		char d[b][b];
		long long e[b];
		long long f[b];
		for(int j=0;j<b;j++){
            e[j]=0;
            f[j]=0;
        }
		for (int j=0;j<b;j++){
			for (int k=0;k<b;k++){
				cin>>c[j][k];
				if (c[j][k]=='#'){
					e[j]++;
				}
			}
		}
		for (int j=0;j<b;j++){
			for (int k=0;k<b;k++){
				cin>>d[j][k];
				if (d[j][k]=='#'){
					f[j]++;
				}
			}
		}
		long long summax=0;
		long long summin=0;
		for (int j=0;j<b;j++){
			summax+=e[j]*f[j];
		}
		cout<<summax<<" ";
		for (int j=0;j<b;j++){
			summin+=max(e[j],f[j]);
		}
		cout<<summin<<endl;
	}
}