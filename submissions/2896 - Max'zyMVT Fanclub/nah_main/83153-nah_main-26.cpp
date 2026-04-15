#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N(1e4+9),MOD(1e9+7),inf(1e18);

int n,power,k,r,cnt=0;
int v[N];
bool ans=false;

void solve(){
	cnt=0;
	int canuse=0;
	cin >> n >> power >> r >> k;
	for(int i=1;i<=n;i++)cin >> v[i];
	int i=1;
	while(i<=n){
		int num = v[i];
		// cout << power << " " << i << "\n";
		if(power>=num){
			power-=num;
			cnt++;
			i++;
			if(cnt==k){
				canuse++;
				cnt=0;
			}
			continue;
		}else{
			// cout << "canuse : " << canuse << "\n";
			while(canuse && power<num){
				power+=r;
				canuse--;
			}
			// cout << power << " " << i << "\n";
			if(power>=num){
				power-=num;
				cnt++;
				i++;
				if(cnt==k){
					canuse++;
					cnt=0;
				}
				continue;
			}
		}
		break;
	}
	// cout << i << "\n";
	if(i-1==n)cout << "nah i'd win\n";
	else cout << "nah i'd lose\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int q=1;
	cin >> q;
	while(q--)solve();
	return 0;
}