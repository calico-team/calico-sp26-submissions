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
    int n; cin >> n; 
    vector<vector<char>> a(n, vector<char>(n)); for(auto &u : a) for(auto &l : u) cin >> l; 
    vector<vector<char>> b(n, vector<char>(n)); for(auto &u : b) for(auto &l : u) cin >> l; 
    ll an1 = 0, an2 = 0; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '#') an2++; 
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(b[i][j] == '#') an2++; 
        }
    }
    for(int i = 0; i < n; i++) {
        ll v1 = 0, v2 = 0; 
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '#') v1++; 
            if(b[i][j] == '#') v2++; 
        }
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '#') an1 += v2; 
        }
        an2 -= min(v1, v2); 
    }
    cout << an1 << " " << an2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    
    while(t--) solve(); 
}