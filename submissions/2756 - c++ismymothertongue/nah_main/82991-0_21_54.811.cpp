#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++){
		int n, p, r, k;
		cin >> n >> p >> r >> k;
		int power = p;
		int cnt = 0;
		bool able = true;
		vector <int> v (n);
		for (int j = 0; j < n; j++){
			cin >> v[j];
		}
		for (int j = 0; j < n; j++){
			if (power < v[j]){
				able = false;
				break;
			}
			power -= v[j];
			cnt += 1;
			if (cnt == k){
				power += r;
				cnt = 0;
			}
		}
		if (able){
			cout << "nah i'd win" << endl;
		}
		else {
			cout << "nah i'd lose" << endl;
		}
	}
}
