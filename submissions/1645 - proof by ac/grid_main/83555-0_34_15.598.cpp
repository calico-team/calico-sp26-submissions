// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i = 0;i<n;++i){
        cin>>arr[i];
    }

    vector<ll> ans;
    ans.push_back(arr[0]);

    for(ll i = 1;i<n-1;++i){
        ll m = min(ans.back(),arr[i]);
        ll M = max(ans.back(),arr[i]);
        ll x = arr[i+1];
        if(x>M){
            x=M;
        }else if(x<m){
            x=m;
        }
        ans.push_back(x);
    }
    ans.push_back(arr.back());

    for(ll a:ans){
        cout<<a<<" ";
    }cout<<endl;

}

int main() {
    ll T;
    cin>>T;
    while(T--){
        solve();
    }
}
