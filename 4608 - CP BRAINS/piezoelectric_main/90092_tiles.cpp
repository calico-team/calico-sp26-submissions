#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define f(i, n) for (ll i = 0; i < n; ++i)

// Problem Statement
/*
  
*/

// Small Observations
/*
  
*/

// Claims on Algo
/*
  
*/

void solve() {
    int L, W, E , R;
    cin >> L >> W >> E >> R;

    int perimeter = 2 * (L+W);

    int oneLapEnergy = perimeter * R;

    cout << E / oneLapEnergy << endl;
   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}