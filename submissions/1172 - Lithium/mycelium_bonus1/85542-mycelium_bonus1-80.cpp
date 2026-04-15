#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define endl '\n'
#define b 2500
int xg,yg,xm,ym,T,tx[4]={0,0,-1,1},ty[4]={-1,1,0,0};
bool have[5000][5000];
void tag(int u,int v){
	have[u+b][v+b]=1;
}
bool vis(int u,int v){
	return have[u+b][v+b];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>xg>>yg>>xm>>ym;
		memset(have,0,sizeof(have));
		vector<pair<int,int> > ng[2],nm[2];
		pair<int,int> p;
		int cntm=0;
		bool flag=0,flam=0;
		p.first=xg,p.second=yg;
		ng[!flag].push_back(p);
		p.first=xm,p.second=ym;
		nm[!flam].push_back(p);
		flag=!flag;flam=!flam;
		int t=0;
		while(!nm[flam].empty()){
			if(t%2==0){
				ng[!flag].clear();
				for(auto g:ng[flag]){
					int x=g.first,y=g.second;
					if(vis(x,y)) continue;
					tag(x,y);
					for(int i=0;i<4;i++){
						if(!vis(x+tx[i],y+ty[i])){
							p.first=x+tx[i],p.second=y+ty[i];
							ng[!flag].push_back(p);
						}
					}
				}
				flag=!flag;
			}
			if(t%7==0){
				nm[!flam].clear();
				for(auto m:nm[flam]){
					int x=m.first,y=m.second;
					if(vis(x,y)) continue;
					tag(x,y);
					cntm++;
					for(int i=0;i<4;i++){
						if(!vis(x+tx[i],y+ty[i])){
							p.first=x+tx[i],p.second=y+ty[i];
							nm[!flam].push_back(p);
						}
					}
				}
				flam=!flam;
			}
			t++;
		}
		cout<<cntm<<endl;
	}
	return 0;
}