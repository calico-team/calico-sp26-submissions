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
int ans;
int x11,y11,x2,y2;
int ok[1009][1009];
int k=500;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
signed main(){
	T=read();
	while(T--){
		x11=read(); y11=read(); x2=read(); y2=read();
		ans=0;
		k=max(abs(x2-x11),abs(y2-y11))+max(abs(x2-x11),abs(y2-y11))+max(abs(x2-x11),abs(y2-y11))/2;
		for(int i=-k;i<=k;i++)
			for(int j=-k;j<=k;j++)
				ok[i+k][j+k]=0;
		ok[x11+k][y11+k]=1;
		ok[x2+k][y2+k]=2;
		priority_queue<array<int,4> > pq;
		pq.push({-2,-1,x11,y11});
		pq.push({-7,-2,x2,y2});
		while(!pq.empty()){
			array<int,4> arr=pq.top();
			pq.pop();
			for(int kk=0;kk<4;kk++){
				int nx=arr[2]+dx[kk];
				int ny=arr[3]+dy[kk];
				if(nx<-k||nx>k||ny<-k||ny>k||ok[nx+k][ny+k])
					continue;
				ok[nx+k][ny+k]=-arr[1];
//				cout<<nx<<" "<<ny<<" "<<ok[nx+k][ny+k]<<endl;
				pq.push({arr[0]-(arr[1]==-1?2:7),arr[1],nx,ny});
			}
		}
		for(int i=-k;i<=k;i++)
			for(int j=-k;j<=k;j++)
				ans+=(ok[i+k][j+k]==2);
//				if(ok[i+k][j+k]==2)
//					cout<<i<<" "<<j<<endl,ans++;
		write(ans);
		putchar('\n');
	}
	return 0;
}