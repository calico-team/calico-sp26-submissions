#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
char s[1003][1003];
int cnt[2003][2003];
int pre[2003][2003];
int sz;

array<int, 2> f(int x){
	for(int xl=1; xl<=sz; xl++){
		int xr = min(sz, xl+x);
		for(int yl=1; yl<=sz; yl++){
			int yr = min(sz, yl+x);
			if(pre[xr][yr]-pre[xl-1][yr]-pre[xr][yl-1]+pre[xl-1][yl-1] >= k) return {xl, yl};
		}
	}
	return {-1, -1};
}

void solve(){
	memset(cnt, 0, sizeof cnt);
	memset(pre, 0, sizeof pre);
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++){
		scanf(" %s", s[i]+1);
	}
	sz = n+m-1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i][j] == '-'){
				cnt[i+j-1][i-j+m] = 1;
			}
		}
	}
	for(int i=1; i<=sz; i++){
		for(int j=1; j<=sz; j++){
			pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+cnt[i][j];
		}
	}
	int l = 0, r = sz-1, res = 0;
	while(l <= r){
		int md = (l+r)/2;
		if(~f(md)[0]){
			res = md;
			r = md-1;
		}
		else{
			l = md+1;
		}
	}
	auto [sx, sy] = f(res);
	int ex = sx+res, ey = sy+res;
	int nok = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i][j] == '-'){
				int r = i+j-1;
				int c = i-j+m;
				if(sx <= r && r <= ex && sy <= c && c <= ey){
					printf("%d %d\n", i-1, j-1);
					nok++;
					if(nok == k) return;
				}
			}
		}
	}
}

int main(){
	int t = 1;
	scanf("%d", &t);
	while(t--) solve();
}