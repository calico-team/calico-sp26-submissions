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
#define int long long

ll power(ll a, ll b){
	if (b == 0) return 1;
	ll res = power(a, b / 2);
//	if (b % 2 == 1) return res * res % MOD * a % MOD;
//	return res * res % MOD;
	
	if (b % 2 == 1) return res * res * a;
	return res * res;
}

struct Node{
	int top, bot;
	int x, y;
	Node(int x, int y, int top, int bot){
		this->x = x;
		this->y = y;
		this->top = top;
		this->bot = bot;
//		top = bottom = 1;
	}
};

int lcm(int a, int b){
	return a / __gcd(a, b) * b;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int xDir[] = {0, 0, -1, 1};
	int yDir[] = {-1, 1, 0, 0};
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		queue<Node> q;
		vector<string> nums(n);
		for (int i = 0; i < n; i++) cin >> nums[i];
		q.push(Node(0, 0, 1, 1));
		vector<pair<int, int>> ans;
//		cout << "TES\n";
		while(!q.empty()){
//			cout << "TES2\n";
			int x = q.front().x;
			int y = q.front().y;
			int top = q.front().top;
			int bot = q.front().bot;
			q.pop();
			if (x < 0 || x >= n || y < 0 || y >= m){
				ans.pb({top, bot});
				continue;
			}
			if (nums[x][y] == '>'){
				q.push(Node(x, y + 1, top, bot));
				continue;
			}
			else if (nums[x][y] == 'v'){
				q.push(Node(x + 1, y, top, bot));
				continue;
			}
			else if (nums[x][y] == '^'){
				q.push(Node(x - 1, y, top, bot));
				continue;
			}
			else if (nums[x][y] == '<'){
				q.push(Node(x, y - 1, top, bot));
				continue;
			}
			if (nums[x][y] == 'X') continue;
			if (nums[x][y] == 'S'){
				int amount = 0;
				for (int i = 0; i < 4; i++){
					int newX = x + xDir[i];
					int newY = y + yDir[i];
					if (newX < 0 || newX >= n || newY < 0 || newY >= m){
						amount++;
						continue;
					}
					if (nums[newX][newY] == '.') continue;
					if (i == 0 && nums[newX][newY] == '>') continue;
					else if (i == 1 && nums[newX][newY] == '<') continue;
					else if (i == 2 && nums[newX][newY] == 'v') continue;
					else if (i == 3 && nums[newX][newY] == '^') continue;
					amount++;
				}
//				cout << amount << " HEHE\n";
				//hrusny ga mungkin amount == 0
				for (int i = 0; i < 4; i++){
					int newX = x + xDir[i];
					int newY = y + yDir[i];
					if (newX < 0 || newX >= n || newY < 0 || newY >= m){
						q.push(Node(newX, newY, top, bot * amount));
						continue;
					}
					if (nums[newX][newY] == '.') continue;
					if (i == 0 && nums[newX][newY] == '>') continue;
					else if (i == 1 && nums[newX][newY] == '<') continue;
					else if (i == 2 && nums[newX][newY] == 'v') continue;
					else if (i == 3 && nums[newX][newY] == '^') continue;
					q.push(Node(newX, newY, top, bot * amount));
				}
			}
		}
		if (ans.empty()){
			cout << "0 1\n";
			continue;
		}
//		cout << ans.size() << " HE\n";
		pair<int, int> yes = ans[0];
		for (int i = 1; i < ans.size(); i++){
//			cout << yes.first << ", " << yes.second << " " << ans[i].first << " " << ans[i].second << "\n";
			int chicken = lcm(yes.second, ans[i].second);
//			cout << chicken << " GG\n";
			yes.first *= chicken / yes.second;
			ans[i].first *= chicken / ans[i].second;
			yes.first += ans[i].first;
			yes.second = chicken;
		}
		int div = __gcd(yes.first, yes.second);
		yes.first /= div;
		yes.second /= div;
		cout << yes.first << " " << yes.second << "\n";
	}
	
	return 0;
}