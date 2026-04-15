#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O1")
#define ll long long
#define pii pair<ll,ll>
#define pi pair<ll,pii>
#define fi first
#define se second

const ll N=1e5+1005,MOD=1e9+7,INF=1e18;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t=1;cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int id=0;
        for(char i : s){
            if(id>=t.size()){
                cout<<"#";
                continue;
            }
            if(i==t[id]){
                cout<<i;
                id++;
            }
            else cout<<"#";
        }
        cout<<"\n";
    }
}
