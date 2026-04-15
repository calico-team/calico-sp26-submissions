#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p, a, b;
char res[3][2003];

ll cal(int a, int b, ll cap){
	ll ret = 1;
	for(int i=0; i<a; i++){
		if(ret > cap/2) return cap+1;
		ret *= 2;
	}
	for(int i=0; i<b; i++){
		if(ret > cap/3) return cap+1;
		ret *= 3;
	}
	return ret;
}

void solve(){
	scanf("%lld %lld %lld", &p, &a, &b);
	vector<array<char, 3>> v;
	while(1){
		if(a){
			ll tmp = cal(a-1, b, p);
			if(p < tmp){
				v.push_back({'X', '>', '.'});
				a--;
			}
			else if(p == tmp){
				v.push_back({'X', '>', '.'});
				p = 0;
				a--;
				break;
			}
			else{
				v.push_back({'^', '>', '.'});
				p -= tmp;
				a--;
			}
		}
		else{
			ll tmp = cal(0, b-1, p);
			ll q, r;
			if(tmp > p){
				q = 0;
				r = p;
			}
			else{
				q = p/tmp;
				r = p%tmp;
			}
			if(r > 0){
				if(q == 0){
					v.push_back({'X', '>', 'X'});
				}
				else if(q == 1){
					v.push_back({'^', '>', 'X'});
				}
				else{
					v.push_back({'^', '>', 'v'});
				}
				p = r;
				b--;
			}
			else{
				if(q == 1){
					v.push_back({'^', 'X', 'X'});
				}
				else{
					v.push_back({'^', '>', 'X'});
				}
				b--;
				break;
			}
		}
	}
	int l = v.size();
	int n = 3, m = 2*l+1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			res[i][j] = '.';
		}
	}
	res[0][0] = 'v';
	res[1][0] = '>';
	for(int i=0; i<l; i++){
		int t = 2*i+1;
		res[1][t] = 'S';
		res[0][t] = v[i][0];
		res[1][t+1] = v[i][1];
		res[2][t] = v[i][2];
	}
	printf("%d %d\n", n, m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%c", res[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int t = 1;
	scanf("%d", &t);
	while(t--) solve();
}