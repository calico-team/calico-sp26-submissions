#include<bits/stdc++.h>
#define int long long
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
int n,p,r,k;
int a[200009];
signed main(){
	T=read();
	while(T--){
		n=read(); p=read(); r=read(); k=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		bool ok=1;
		for(int i=1;i<=n;i++){
			p-=a[i];
			ok&=(p>=0);
			if(i%k==0)
				p+=r;
		}
		printf(ok?"nah i'd win\n":"nah i'd lose\n");
	}
	return 0;
}