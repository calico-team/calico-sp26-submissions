#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> vx,vy,vx2,vy2;
ll ans=1;
bool zy[6005][6005],zy2[6005][6005];
void pb(ll x,ll y){
	if(x-1>=0&&!zy[x-1][y]&&!zy2[x-1][y]){
		vx.push(x-1);
		vy.push(y);
	}
	if(x+1>=0&&!zy[x+1][y]&&!zy2[x+1][y]){
		vx.push(x+1);
		vy.push(y);
	}
	if(y-1>=0&&!zy[x][y-1]&&!zy2[x][y-1]){
		vx.push(x);
		vy.push(y-1);
	}
	if(y+1>=0&&!zy[x][y+1]&&!zy2[x][y+1]){
		vx.push(x);
		vy.push(y+1);
	}
	return;
}
void pb2(ll x,ll y){
	if(x-1>=0&&!zy[x-1][y]&&!zy2[x-1][y]){
		vx2.push(x-1);
		vy2.push(y);
	}
	if(x+1>=0&&!zy[x+1][y]&&!zy2[x+1][y]){
		vx2.push(x+1);
		vy2.push(y);
	}
	if(y-1>=0&&!zy[x][y-1]&&!zy2[x][y-1]){
		vx2.push(x);
		vy2.push(y-1);
	}
	if(y+1>=0&&!zy[x][y+1]&&!zy2[x][y+1]){
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
		x1+=3000;
		y1+=3000;
		x2+=3000;
		y2+=3000;
		memset(zy,0,sizeof(zy));
		zy[x1][y1]=1;
		memset(zy2,0,sizeof(zy2));
		zy2[x2][y2]=1;
		pb(x1,y1);
		pb2(x2,y2);
		//cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		while(!vx.empty()&&!vx2.empty()){
			if(t%2==0){
				vector<ll> jjx,jjy;
				while(!vx.empty()){
					jjx.push_back(vx.front());
					jjy.push_back(vy.front());
					vx.pop();
					vy.pop();
				}
				for(ll i=0;i<jjx.size();i++){
					if(!zy[jjx[i]][jjy[i]]&&!zy2[jjx[i]][jjy[i]]){
						pb(jjx[i],jjy[i]);
						zy[jjx[i]][jjy[i]]=1;
						//if(jjx[i]>=2990&&jjx[i]<=3010&&jjy[i]>=2990&&jjy[i]<=3010)cout<<jjx[i]-3000<<" "<<jjy[i]-3000<<" c "<<t<<endl;
					}
				}
			}
			if(t%7==0){
				vector<ll> jjx,jjy;
				while(!vx2.empty()){
					jjx.push_back(vx2.front());
					jjy.push_back(vy2.front());
					vx2.pop();
					vy2.pop();
				}
				for(ll i=0;i<jjx.size();i++){
						//cout<<jjx[i]-3000<<" "<<jjy[i]-3000<<" "<<zy[jjx[i]][jjy[i]]<<endl;
					if(!zy[jjx[i]][jjy[i]]&&!zy2[jjx[i]][jjy[i]]){
						pb2(jjx[i],jjy[i]);
						zy2[jjx[i]][jjy[i]]=1;
						ans++;
					}
				}
			}
			t++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
