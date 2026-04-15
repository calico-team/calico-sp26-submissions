#include<bits/stdc++.h>
using namespace std;

void FREOPEN(const string &prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

#define debug(c) cout << #c << " = " << c << endl
#define debugc() cout << "PASS" << endl

#define nl "\n"
#define fl flush
#define int long long

#define ll long long
#define str string
#define ld long double

#define Pb push_back
#define pB pop_back
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define ft first
#define sc second

void solve() {
    int n; cin >> n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> L(n), R(n);
    L[0] = a[0], R[0] = a[0];

    for(int i=1;i<n;i++) {
        vector<int> pt = {L[i-1], R[i-1], a[i], a[i]};
        sort(all(pt));

        L[i] = pt[1], R[i] = pt[2]; 
    }

    vector<int> b(n);
    b[n-1] = L[n-1]; 

    for(int i=n-2;i>=0;i--) b[i] = max(L[i], min(b[i+1], R[i])); 
    for(int i=0;i<n;i++) 
        cout << b[i] << (i == n - 1 ? "\n" : " ");
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0); 
    // FREOPEN("");
    
    int T = 1; cin >> T;
    while(T--) solve();
}
