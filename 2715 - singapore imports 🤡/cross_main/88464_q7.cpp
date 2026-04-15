#include <bits/stdc++.h>
using namespace std;
#define int long long

main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int T;
	cin>>T;
	vector<pair<int,int>> check={{0,-2},{0,2},{2,0},{-2,0},
		{0,-1},{0,1},{-1,0},{1,0},
		{1,1},{1,-1},{-1,-1},{-1,1},
		{0,0}};
	for(int _=0;_<T;_++){
		int N,M;
		cin>>N>>M;
		unordered_map<int,vector<vector<bool>>> m;
		for(int i=1;i<=4;i++){
			m[i]=vector<vector<bool>>(1001,vector<bool>(1001,false));
		}
		for(int y=0;y<N;y++){
			for(int x=0;x<M;x++){
				if( (y==0 && x==0) || 
				(y==0 && x==M-1) ||
				(y==N-1 && x==0) ||
				(y==N-1 && x==M-1 )){cout<<0<<' ';continue;}
				int rsp=0;
				for(int i=1;i<=4;i++){
					if(!m[i][y][x]){rsp=i;break;}
				}
				if(rsp!=0){
					for(int p=0;p<13;p++){
						int X=x+check[p].first,Y=y+check[p].second;
						//~ cout<<X<<' '<<Y<<endl;
						//~ cout<<m[rsp][X][Y]<<endl;
						if( X>=0 and X<=M-1 and
						Y>=0 and Y<=N-1){
							m[rsp][Y][X]=true;
						}
					}
				
				}
				cout<<rsp<<' ';
			}
			cout<<endl;
			
		}
	}
	return 0;
}

