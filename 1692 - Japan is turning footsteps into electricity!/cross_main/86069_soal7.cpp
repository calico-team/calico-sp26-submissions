#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T>
using ordered_set = tree<T, null_type, less<T>, 
					rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag,
					tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define MOD 998244353
#define MAXN 250000
#define SIZE 100
#define pb push_back

ll power(ll a, ll b){
	if (b == 0) return 1;
	ll res = power(a, b / 2);
//	if (b % 2 == 1) return res * res % MOD * a % MOD;
//	return res * res % MOD;
	
	if (b % 2 == 1) return res * res * a;
	return res * res;
}

struct Node{
	int cost, type, x, y;
	Node(int cost, int type, int x, int y){
		this->cost = cost;
		this->type = type;
		this->x = x;
		this->y = y;
	}
	bool operator<(const Node& a) const
    {
    	if (cost == a.cost) return type > a.type;
        return cost > a.cost;
    }
};

int xDir[] = {0, 0, -1, 1};
int yDir[] = {-1, 1, 0, 0};

bool check(vector<vector<int>> &all, int n, int m, int x, int y){
	map<int, bool> exist;
	exist[all[x][y]] = 1;
	int bad = 0;
	for (int i = 0; i < 4; i++){
		int newX = x + xDir[i];
		int newY = y + yDir[i];
		if (newX < 0 || newX >= n || newY < 0 || newY >= m) return 1;
		if (exist.count(all[newX][newY])) bad++;
		exist[all[newX][newY]] = 1;
	}
//	if (i == 2 && j == )
	if (bad) return 0;
	return 1;
}

int setNo(vector<bool> &canUse, vector<vector<int>> &ans, int n, int m, int i, int j){
	for (int k = 0; k < 5; k++) canUse[k] = 1;
	int x = i - 1;
	int y = j - 1;
	if (ans[x][y] != -1) canUse[ans[x][y]] = 0;
	for (int k = 0; k < 4; k++){
		int newX = x + xDir[k];
		int newY = y + yDir[k];
		if (ans[newX][newY] != -1) canUse[ans[newX][newY]] = 0;
	}
	int cnt = 0;
	for (int k = 0; k < 5; k++) if (canUse[k]) cnt++;
//	if (i == 3 && j == 3) {
//		cout << cnt << " AAAAAAAAAA\n";
//		for (int a = 0; a < n; a++){
//					for (int b = 0; b < m; b++){
//						cout << ans[a][b] << " ";
//					}
//					cout << "\n";
//				}
//	}
	return cnt;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	vector<bool> canUse(5, 1);
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> ans(n, vector<int>(m, -1));
		ans[0][1] = 0;
		ans[1][0] = 1;
		ans[1][1] = 3;
		ans[1][2] = 4;
		ans[2][1] = 2;
		for (int j = 3; j < m; j++){
			ans[2][j - 1] = ans[0][j - 2];
			ans[0][j - 1] = ans[1][j - 3];
			ans[1][j] = ans[2][j - 2];
		}
		for (int i = 3; i < n; i++){
			for (int j = 2; j < m; j++){
				int cnt = setNo(canUse, ans, n, m, i, j);
//				cout << i << ", " << j << " HHE\n";
//				for (int a = 0; a < n; a++){
//					for (int b = 0; b < m; b++){
//						cout << ans[a][b] << " ";
//					}
//					cout << "\n";
//				}
//				cout << "\n\n";
				if (cnt > 1){
					if (j == 2){
						ans[i][j - 1] = ans[i - 2][j - 2];
						canUse[ans[i][j - 1]] = 0;
						int val = 0;
						for (int k = 0; k < 5; k++){
							if (canUse[k]) val = k;
						}
						ans[i - 1][j - 2] = val;
					}
					else{
//					cout << i << ", " << j << " HHE\n";
						ans[i - 1][j] = ans[i][j - 2];
						canUse[ans[i - 1][j]] = 0;
//						for (int a = 0; a < n; a++){
//					for (int b = 0; b < m; b++){
//						cout << ans[a][b] << " ";
//					}
//					cout << "\n";
//				}
//				cout << "\n\n";
						int val = 0;
						for (int k = 0; k < 5; k++){
							if (canUse[k]) val = k;
						}
						ans[i][j - 1] = val;
					}
				}
				else{
					int val = 0;
					for (int k = 0; k < 5; k++){
						if (canUse[k]) val = k;
					}
					ans[i][j - 1] = val;
				}
//				cout << i << ", " << j << " HHE\n";
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (ans[i][j] == -1) ans[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
//		cout << "\n\n";
		
//		bool can = 1;
//		int wrongX, wrongY;
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < m; j++){
//				if (!check(ans, n, m, i, j)){
//					can = 0;
//					wrongX = i;
//					wrongY = j;
//					break;
//				}
//			}
//			if (!can) break;
//		}
//		if (can) cout << "YES\n";
//		else {
//			cout << "NO\n";	
//			cout << wrongX << " " << wrongY << "\n";
//		}
	}
	
	return 0;
}