using namespace std;
#include <bits/stdc++.h>
 
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
 
#define ll long long
#define read(arr) for (auto &x: arr) cin >> x;
#define print_vec(arr) for (auto arr_val: arr) { cout << arr_val << " "; } cout << endl
 
// https://codeforces.com/blog/entry/70327, written 5 years ago
ll mod_pow(ll a, ll b, ll m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

// https://usaco.guide/gold/hashing?lang=cpp
long long rng() {
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> vec(n, vector<int>(m, -1));

        vec[0][1] = 0;
        vec[1][1] = 1;
        vec[1][0] = 2;
        vec[1][2] = 3;
        vec[2][1] = 4;

        queue<array<int, 2>> bfs;
        bfs.push({1, 1});
        vector<vector<bool>> visited(n, vector<bool>(m));
        
        while (bfs.size() > 0) {
            auto top = bfs.front(); bfs.pop();
            int i = top[0];
            int j = top[1];
            if (visited[i][j]) continue;
            if (i == 0 || i == n-1 || j == 0 || j == m-1) continue;
            visited[i][j] = true;
            set<int> s = {vec[i][j], vec[i+1][j], vec[i-1][j], vec[i][j+1], vec[i][j-1]};
            if (s.size() < 5) {
                assert(false);//exit(0);
            }
            else if (s.size() == 5 && s.count(-1)) {
               // print_vec(top);
                int missing = -1;
                for (int i = 0; i <= 4; i++) {
                    if (!s.count(i)) missing = i;
                }
               // cerr << missing << "\n";
                if (vec[i][j] == -1) vec[i][j] = missing;
                else if (vec[i+1][j] == -1) vec[i+1][j] = missing;
                else if (vec[i-1][j] == -1) vec[i-1][j] = missing;
                else if (vec[i][j+1] == -1) vec[i][j+1] = missing;
                else if (vec[i][j-1] == -1) vec[i][j-1] = missing;
                else assert(false);
            }
            array<int, 4> pairs[4] = {{i-1, j, i+1, j+1}, {i+1, j, i-1, j-1}, {i, j-1, i-1, j+1}, {i, j+1, i+1, j-1}};
            for (auto &x: pairs) {
                //print_vec(x);
                vec[x[2]][x[3]] = vec[x[0]][x[1]];
            }

            
            bfs.push({i+1, j});
            bfs.push({i-1, j});
            bfs.push({i, j+1});
            bfs.push({i, j-1});
            /*
            print_vec(top);
                for (auto &x: vec) {
                    for (auto &y: x) cout << (y == -1 ? 7 : y);
                    cout << "\n";
                }
            */
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vec[i][j] == -1) { vec[i][j] = 0; }
            }
        }
       
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                set<int> s = {vec[i][j], vec[i+1][j], vec[i-1][j], vec[i][j+1], vec[i][j-1]};
                assert(s.size() == 5);
            }
        }
        for (auto &x: vec) {
            for (auto &y: x) cout << y << " ";
            cout << "\n";
        }
    }
}
