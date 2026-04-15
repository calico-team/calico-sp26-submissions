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


void solve() {
    int n; cin >> n; 
    vector<int> a(n); for(auto &u : a) cin >> u; 
    if(n == 1) { cout << a[0] << "\n"; return; }
    if(n == 2) { cout << a[0] << " " << a[1] << "\n"; return; }
    vector<int> ans(n); 
    for(int i = 1; i < n - 1; i++) {
        
        if(min(a[i - 1], a[i + 1]) <= a[i] && a[i] <= max(a[i - 1], a[i + 1])) ans[i] = a[i]; 
        else if(a[i] <= min(a[i - 1], a[i + 1])) ans[i] = min(a[i - 1], a[i + 1]);
        else ans[i] = max(a[i - 1], a[i + 1]);
        
    }
    ans[0] = ans[1]; 
    ans[n - 1] = ans[n - 2]; 
    for(auto &u : ans) cout << u << " "; cout << "\n"; 
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    
    while(t--) solve(); 
}