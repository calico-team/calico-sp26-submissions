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


void solve() {
    int n; cin >> n; 
    vector<int> a(n); for(auto &u : a) cin >> u; 
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n - 1) cout << a[i] << " \n"[i == n - 1]; 
        else {
            if(min(a[i - 1], a[i + 1]) <= a[i] && a[i] <= max(a[i - 1], a[i + 1])) cout << a[i] << " "; 
            else if(a[i] <= min(a[i - 1], a[i + 1])) cout << min(a[i - 1], a[i + 1]) << " "; 
            else cout << max(a[i - 1], a[i + 1]) << " "; 
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int t; cin >> t; 
    
    while(t--) solve(); 
}