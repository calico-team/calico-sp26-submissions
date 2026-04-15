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
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[i][j] = ((2 * i) + j) % 5; 
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