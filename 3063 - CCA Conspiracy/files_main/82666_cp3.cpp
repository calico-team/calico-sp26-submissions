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
    string a,b;cin>>a>>b;
    int la = a.size(),j=0;

    for(int i=0;i<la;i++){
        if(a[i]==b[j]){
            j++;
            cout<<a[i];
        } else{
            cout<<"#";
        }
    }
    cout<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while (t--) solve();
}
