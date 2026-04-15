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
// machine learning ?!!
int n,m,d;
int a[40009];
double tot[40009];
double b[40009];
array<int,4> aa[2000009];
pair<double,int> p[2000009];
signed main(){
	n=read(); m=read(); d=read();
	for(int i=1;i<=m;i++)
		for(int j=0;j<4;j++)
			aa[i][j]=read();
	for(int i=1;i<=m;i++){
		b[aa[i][0]]+=(double)aa[i][3]/(double)aa[i][2]*((double)sqrt((double)aa[i][2]));
		tot[aa[i][0]]+=aa[i][3]/(double)aa[i][2];
		b[aa[i][1]]+=(double)aa[i][3]/(double)aa[i][2]*((double)sqrt((double)aa[i][2]));
		tot[aa[i][1]]+=aa[i][3]/(double)aa[i][2];
	}
	for(int i=1;i<=n;i++)
		a[i]=max(1ll,(int)floor(b[i]/tot[i]+0.5));
	for(int i=1;i<=m;i++){
		double ans=(double)aa[i][3]/(double)aa[i][2];
		ans=ans*(double)(abs((a[aa[i][0]]*a[aa[i][1]])-aa[i][2]));
		p[i]=make_pair(ans,i);
	}
	for(int i=1;i<=n;i++,putchar(' '))
		write(a[i]);
	putchar('\n');
	write(d);
	putchar(' ');
	for(int i=1;i<=d;i++,putchar(' '))
		write(p[i].second);
	return 0;
}
