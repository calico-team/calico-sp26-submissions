#include <iostream> 
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <unordered_set>
#include <stack>
#include <random>
#include <chrono>
#include <bitset>
#include <complex>
#include <cassert>
#include <functional>
#include <ctime>



#pragma GCC optimize ("O3")

using namespace std; 



#define ll long long
#define f first
#define s second



// 
// 
// 

const ll inf = (ll) 1e18 + 7; 
void solve() {
    int n, m; cin >> n >> m; 
    int ct = 0; 
    vector<vector<int>> ans(n, vector<int>(m)); 
    for(int i = 0; i < m; i++) ans[0][i] = i % 5; 
    if(n > 1) for(int i = 0; i < m; i++) ans[1][i] = (i + 2) % 5; 
    for(int i = 2; i < n; i++) {
        for(int j = 1; j < m - 1; j++) {
            set<int> p = {0, 1, 2, 3, 4}; 
            p.erase(ans[i - 1][j]);
            p.erase(ans[i - 1][j - 1]);
            p.erase(ans[i - 1][j + 1]);
            p.erase(ans[i - 2][j]);
            ans[i][j] = *p.begin(); 
        }
        for(int j = 0; j < 1; j++) {
            set<int> p = {0, 1, 2, 3, 4}; 
            p.erase(ans[i][j + 1]);
            p.erase(ans[i - 1][j]); 
            p.erase(ans[i][j + 2]);
            p.erase(ans[i - 1][j + 1]);
            ans[i][j] = *p.begin(); 
        }
        for(int j = m - 1; j < m; j++) {
            set<int> p = {0, 1, 2, 3, 4}; 
            p.erase(ans[i][j - 1]);
            p.erase(ans[i - 1][j]); 
            p.erase(ans[i][j - 2]);
            p.erase(ans[i - 1][j - 1]);
            ans[i][j] = *p.begin(); 
        }
    }
    
    for(auto &u : ans) {
        for(auto &l : u) cout << l << " "; 
        cout << "\n"; 
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    
    while(t--) solve(); 
}