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


// 0 or n - 1 => [a[i], b[i + 1]]
// a, b, c => a[i]
// a, c, b => b[i + 1]
// b, a, c => b[i - 1]

// 1 3 4 2
// 


const int N = (int) 100; 
void solve() {
    ll an = 0; 
    priority_queue<vector<ll>> pq;  
    ll x, y; cin >> x >> y; x += N / 2, y += N / 2; 
    ll a, b; cin >> a >> b; a += N / 2, b += N / 2; 
    pq.push({0, 0, x, y}); 
    pq.push({0, -1, a, b}); 
    vector<vector<bool>> v(N, vector<bool>(N, false));
    while(!pq.empty()) {
        auto u = pq.top(); pq.pop(); 
        if(u[2] < 0 || u[3] < 0 || u[2] >= N || u[3] >= N) continue;
        if(v[u[2]][u[3]]) continue; 
        v[u[2]][u[3]] = true; 
        if(u[1] == -1) an++; 
        pq.push({u[0] - (u[1] == -1 ? 7 : 2), u[1], u[2] + 1, u[3]});
        pq.push({u[0] - (u[1] == -1 ? 7 : 2), u[1], u[2] - 1, u[3]});
        pq.push({u[0] - (u[1] == -1 ? 7 : 2), u[1], u[2], u[3] + 1});
        pq.push({u[0] - (u[1] == -1 ? 7 : 2), u[1], u[2], u[3] - 1});
    }
    cout << an << "\n"; 
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    
    while(t--) solve(); 
}