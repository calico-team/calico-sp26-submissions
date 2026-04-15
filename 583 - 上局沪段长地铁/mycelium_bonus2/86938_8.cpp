#include<bits/stdc++.h>
using namespace std;
#define ll int
ll x1,y3,x2,y2;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
queue<ll> vx,vy,vx2,vy2;
ll ans=1;
bool zy[8005][8005];
ll jdz(ll a){
	if(a<0)return -a;
	return a;
} 
bool zzj(ll x,ll y){
	return x>=min(x1,x2)&&x<=max(x1,x2)&&y>=min(y2,y3)&&y<=max(y2,y3);
}
bool zzj2(ll x,ll y){
	return x<=min(x1,x2)-900||x>=max(x1,x2)+900||y<=min(y2,y3)-900||y>=max(y2,y3)+900;
}
void pb(ll x,ll y){
	if(jdz(x-x2)+jdz(y-y3)>=900&&!zzj(x,y))return;
	if(zzj2(x,y))return;
	if(x-1>=0&&!zy[x-1][y]){
		vx.push(x-1);
		vy.push(y);
	}
	if(x+1<=8000&&!zy[x+1][y]){
		vx.push(x+1);
		vy.push(y);
	}
	if(y-1>=0&&!zy[x][y-1]){
		vx.push(x);
		vy.push(y-1);
	}
	if(y+1<=8000&&!zy[x][y+1]){
		vx.push(x);
		vy.push(y+1);
	}
	return;
}
void pb2(ll x,ll y){
	if(x-1>=0&&!zy[x-1][y]){
		vx2.push(x-1);
		vy2.push(y);
	}
	if(x+1<=8000&&!zy[x+1][y]){
		vx2.push(x+1);
		vy2.push(y);
	}
	if(y-1>=0&&!zy[x][y-1]){
		vx2.push(x);
		vy2.push(y-1);
	}
	if(y+1<=8000&&!zy[x][y+1]){
		vx2.push(x);
		vy2.push(y+1);
	}
	return;
}
int main(){
	ll T=read();
	while(T--){
		while(!vx.empty())vx.pop(),vy.pop();
		while(!vx2.empty())vx2.pop(),vy2.pop();
		x1=read();
		y3=read();
		x2=read();
		y2=read();
		ll t=1;
		ans=1;
		x1+=4000;
		y3+=4000;
		x2+=4000;
		y2+=4000;
		memset(zy,0,sizeof(zy));
		zy[x1][y3]=1;
		//memset(zy2,0,sizeof(zy2));
		zy[x2][y2]=1;
		pb(x1,y3);
		pb2(x2,y2);
		//cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		while(!vx.empty()&&!vx2.empty()){
			if(t%2==0){
				ll jl=vx.size(),kk=0;
				while(!vx.empty()){
					kk++;
					ll jx=vx.front(),jy=vy.front();
					if(!zy[jx][jy]){
						pb(jx,jy);
						zy[jx][jy]=1;
						//if(jjx[i]>=2990&&jjx[i]<=3010&&jjy[i]>=2990&&jjy[i]<=3010)cout<<jjx[i]-3000<<" "<<jjy[i]-3000<<" c "<<t<<endl;
					}
					vx.pop();
					vy.pop();
					if(kk>=jl)break;
				}
			}
			if(t%7==0){
				ll jl=vx2.size(),kk=0;
				while(!vx2.empty()){
					kk++;
					ll jx=vx2.front(),jy=vy2.front();
					if(!zy[jx][jy]){
						pb2(jx,jy);
						zy[jx][jy]=1;
						ans++;
						//if(jjx[i]>=2990&&jjx[i]<=3010&&jjy[i]>=2990&&jjy[i]<=3010)cout<<jjx[i]-3000<<" "<<jjy[i]-3000<<" c "<<t<<endl;
					}
					vx2.pop();
					vy2.pop();
					if(kk>=jl)break;
				}
			}
			t++;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
