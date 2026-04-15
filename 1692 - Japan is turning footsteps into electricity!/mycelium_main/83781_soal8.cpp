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
	
	int t;
	cin >> t;
	while(t--){
		int xg, yg, xm, ym;
		cin >> xg >> yg >> xm >> ym;
		xg += 500;
		yg += 500;
		xm += 500;
		ym += 500;
		vector<vector<int>> tiles(1000, vector<int>(1000, 0));
		priority_queue<Node> pq;
		pq.push(Node(1, 1, xg, yg));
		pq.push(Node(1, 2, xm, ym));
		int ans = 0;
		int myCnt = 1;
		while(!pq.empty() && myCnt != 0){
			auto [cost, type, x, y] = pq.top();
			pq.pop();
			if (type == 2) myCnt--;
			if (tiles[x][y] != 0) continue;
//			if (cost < 22) cout << x - 500<< " " << y - 500<< " " << type << " " << cost<< " gggg\n";
			tiles[x][y] = type;
			if (type == 2) {
//				cout << x - 500<< " " << y - 500<< " " << cost <<" GG\n";
				ans++;
			}
			for (int i = 0; i < 4; i++){
				int newX = x + xDir[i];
				int newY = y + yDir[i];
				if (newX < 0 || newX >= 1000 || newY < 0 || newY >= 1000 || tiles[newX][newY] != 0) continue;
				int add = 2;
				if (cost == 1) add = 1;
				if (type == 2) {
					myCnt++;
					add = 7;
					if (cost == 1) add = 6;
				}
				pq.push(Node(cost + add, type, newX, newY));
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}