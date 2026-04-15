#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N(20);

int n,m;
int a,b;
char tab[N][N];

int check(int x,int y){
	int cnt=0;
	if(x+1>n || tab[x+1][y]=='v'|| tab[x+1][y]=='X'){
		cnt++;
	}
	if(x-1<1 || tab[x-1][y]=='^' || tab[x-1][y]=='X'){
		cnt++;
	}
	if(y+1>m || tab[x][y+1]=='>' || tab[x][y+1]=='X'){
		cnt++;
	}
	if(y-1<1 || tab[x][y-1]=='<' || tab[x][y-1]=='X'){
		cnt++;
	}
	return cnt;
}

int lcm(int a,int b){
	return a*b/__gcd(a,b);
}

pair<int,int> pls(int a,int b,int x,int y){
	int m1=lcm(b,y)/b;
	int m2=lcm(b,y)/y;
	int first = a*m1+x*m2;
	int second = lcm(b,y);
	int g = __gcd(first,second);
	return make_pair(first/g,second/g);
}

void solve(){
	a=0,b=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> tab[i][j];
		}
	}
	queue<tuple<int,int,int>> q;
	q.push({1,1,1});
	while(!q.empty()){
		auto [x,y,stat] = q.front() ; q.pop();
		// cout << x << " " << y << " " << stat << "\n";
		if(x<1||y<1||x>n||y>m){
			pair<int,int> tmp = pls(a,b,1,stat);
			// cout << x << " " << y << " " << stat << "\n";
			a=tmp.first,b=tmp.second;
			// cout << a << " " << b << "\n";
			continue;
		}
		if(tab[x][y]=='v'){
			q.push({x+1,y,stat});
		}else if(tab[x][y]=='^'){
			q.push({x-1,y,stat});
		}else if(tab[x][y]=='>'){
			q.push({x,y+1,stat});
		}else if(tab[x][y]=='<'){
			q.push({x,y-1,stat});
		}else if(tab[x][y]=='S'){
			int cnt = check(x,y);
			if(x+1>n || tab[x+1][y]=='v'|| tab[x+1][y]=='X'){
				q.push({x+1,y,stat*cnt});
			}
			if(x-1<1 || tab[x-1][y]=='^' || tab[x-1][y]=='X'){
				q.push({x-1,y,stat*cnt});
			}
			if(y+1>m || tab[x][y+1]=='>' || tab[x][y+1]=='X'){
				q.push({x,y+1,stat*cnt});
			}
			if(y-1<1 || tab[x][y-1]=='<' || tab[x][y-1]=='X'){
				q.push({x,y-1,stat*cnt});
			}
		}
	}
	cout << a << " " << b << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int q=1;
	cin >> q;
	while(q--)solve();
	return 0;
}