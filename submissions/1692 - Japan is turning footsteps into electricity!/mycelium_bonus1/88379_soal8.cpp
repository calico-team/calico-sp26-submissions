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

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int xDir[] = {0, 0, -1, 1};
	int yDir[] = {-1, 1, 0, 0};
	int MAX_SIZE = 1100;
	
	int t;
	cin >> t;
	vector<vector<int>> tiles(MAX_SIZE, vector<int>(MAX_SIZE, 0));
	while(t--){
		int xg, yg, xm, ym;
		cin >> xg >> yg >> xm >> ym;
		xg += MAX_SIZE / 2;
		yg += MAX_SIZE / 2;
		xm += MAX_SIZE / 2;
		ym += MAX_SIZE / 2;
		for (int i = 0; i < MAX_SIZE; i++){
			for (int j = 0; j < MAX_SIZE; j++) tiles[i][j] = 0;
		}
		int ans = 0;
		bool good = 1;
		int gCost = 1;
		int mCost = 1;
		stack<pair<int, int>> allG, allM;
		allG.push({xg, yg});
		allM.push({xm, ym});
		stack<pair<int, int>> temp;
		int op = 0;
//		auto chrono_begin = chrono::steady_clock::now();
		while(!allM.empty()){
//			cout << allG.size() << " " << allM.size() << "\n";
//			cout << gCost << " " << mCost << " COST\n\n";
//			string tes;
//			cin >> tes;
			if (gCost <= mCost){
//				cout << "EYYY\n";
				while(!allG.empty()){
					auto [x, y] = allG.top();
					allG.pop();
					if (tiles[x][y] != 0){
						continue;
					}
					tiles[x][y] = 1;
					for (int i = 0; i < 4; i++){
						int newX = x + xDir[i];
						int newY = y + yDir[i];
//						if ((newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE)) good = 0;
						if (newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE || tiles[newX][newY] != 0) continue;
//						op++;
						temp.push({newX, newY});
					}
				}
				swap(temp, allG);
//				while(!temp.empty()){
//					allG.push(temp.top());
//					temp.pop();
//				}
				int add = 2;
				if (gCost == 1) add = 1;
				gCost += add;
			}
			else{
				while(!allM.empty()){
					auto [x, y] = allM.top();
					allM.pop();
					if (tiles[x][y] != 0){
						continue;
					}
					ans++;
					tiles[x][y] = 2;
					for (int i = 0; i < 4; i++){
						int newX = x + xDir[i];
						int newY = y + yDir[i];
						if ((newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE)) good = 0; 
						if (newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE || tiles[newX][newY] != 0) continue;
						temp.push({newX, newY});
//						op++;
					}
				}
				swap(allM, temp);
//				while(!temp.empty()){
//					allM.push(temp.top());
//					temp.pop();
//				}
				int add = 7;
				if (mCost == 1) add = 6;
				mCost += add;
			}
		}
//		cout << "chrono: " << 1e-6L * chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - chrono_begin).count() << 's' << endl;
//		cout << op << " GG\n";
//		if (!good) cout << "BAD\n";
		cout << ans << "\n";
	}
	
	return 0;
}