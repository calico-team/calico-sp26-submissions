#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
inline int read(){
	int num=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+(int)ch-48;
		ch=getchar();
	}
	return num*sign;
}
inline void write(int num){
	if(num<0){
		putchar('-');
		num=-num;
	}
	if(num>9)
		write(num/10);
	putchar(num%10+'0');
}
int T;
int n,m;
int main(){
	T=read();
	while(T--){
		n=read(); m=read();
		int curr=4;
		for(int i=1;i<=n;i++){
			int cur=curr;
			for(int j=1;j<=m;j++){
				write(cur); putchar(' ');
				cur=(cur+1)%5;
			}
			putchar('\n');
			curr=(curr+2)%5;
		}
	}
	return 0;
}