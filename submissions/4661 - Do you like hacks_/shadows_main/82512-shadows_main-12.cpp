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
int n;
char ch[1009][1009];
char ch2[1009][1009];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
			scanf("%s",ch[i]+1);
		for(int i=1;i<=n;i++)
			scanf("%s",ch2[i]+1);
		int mn=0,mx=0;
		for(int i=1;i<=n;i++){
			int num=0,num2=0;
			for(int j=1;j<=n;j++){
				num+=(ch[i][j]=='#');
				num2+=(ch2[i][j]=='#');
			}
			if(num&&num2){
				mn+=max(num,num2);
				mx+=num*num2;
			}
		}
		write(mx); putchar(' '); write(mn);
		putchar('\n');
	}
	return 0;
}