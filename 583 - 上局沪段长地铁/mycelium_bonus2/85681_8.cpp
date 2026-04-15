#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> vx,vy,vx2,vy2;
ll ans=1;
bool zy[8005][8005];
void pb(ll x,ll y){
	if(x-1>=0&&!zy[x-1][y]){
		vx.push(x-1);
		vy.push(y);
	}
	if(x+1>=0&&!zy[x+1][y]){
		vx.push(x+1);
		vy.push(y);
	}
	if(y-1>=0&&!zy[x][y-1]){
		vx.push(x);
		vy.push(y-1);
	}
	if(y+1>=0&&!zy[x][y+1]){
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
	if(x+1>=0&&!zy[x+1][y]){
		vx2.push(x+1);
		vy2.push(y);
	}
	if(y-1>=0&&!zy[x][y-1]){
		vx2.push(x);
		vy2.push(y-1);
	}
	if(y+1>=0&&!zy[x][y+1]){
		vx2.push(x);
		vy2.push(y+1);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		while(!vx.empty())vx.pop(),vy.pop();
		while(!vx2.empty())vx2.pop(),vy2.pop();
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ll t=1;
		ans=1;
		x1+=4000;
		y1+=4000;
		x2+=4000;
		y2+=4000;
		memset(zy,0,sizeof(zy));
		zy[x1][y1]=1;
		//memset(zy2,0,sizeof(zy2));
		zy[x2][y2]=1;
		pb(x1,y1);
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
		cout<<ans<<endl;
	}
	return 0;
}
