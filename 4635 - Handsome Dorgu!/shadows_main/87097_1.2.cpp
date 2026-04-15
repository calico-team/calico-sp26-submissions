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
		long long e[b+10];
		long long f[b+10];
		for(int j=0;j<b;j++){
            e[j]=0;
            f[j]=0;
        }
		for (int j=0;j<b;j++){
            string s;
            cin>>s;
            for (int k=0;k<b;k++){
                if (s[k]=='#'){
                    e[j]++;
                }
            }
        }
        for (int j=0;j<b;j++){
            string s;
            cin>>s;
            for (int k=0;k<b;k++){
                if (s[k]=='#'){
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