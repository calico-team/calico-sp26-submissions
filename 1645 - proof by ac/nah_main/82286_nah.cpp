// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
    ll n,p,r,k;
    cin>>n>>p>>r>>k;
    ll cnt = 0;
    vector<ll> spirits(n);
    for(ll i = 0;i<n;++i){
        cin>>spirits[i];
    }
    ll exor = 0;
    for(int i = 0;i<n;++i){
        p-=spirits[i];
        if(p<0){
            cout<<"nah i'd lose"<<endl;
            return;
        }
        
        if((i+1)%k == 0){
            p+=r;
        }
    }

    cout<<"nah i'd win"<<endl;
}

int main() {
    ll T;
    cin>>T;
    while(T--){
        solve();
    }
    
}
