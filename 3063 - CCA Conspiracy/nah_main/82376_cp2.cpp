#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 1e9+7;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;


void solve(){
    int n,p,r,k;cin>>n>>p>>r>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++){
        p-=a[i];
        if(p<0){
            cout<<"nah i'd lose\n";
            return;
        }
        if((i+1)%k==0) p+=r;
    }
    cout<<"nah i'd win\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while (t--) solve();
}
