#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k,m,n,p,q;
        cin >> k >> n >> m >> p >> q;
        map<pair<int,int>,int>mp;
        int si,sj;
        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            if(i==0){
                si=y,sj=x;
            }
            mp[{y,x}]=i+1;
        }
        int i=si,j=sj;
        set<pair<int,int>>flag;
        while(1){
            i=(i+p)%m;
            j=(j+q)%n;
            if(flag.count({i,j})) break;
            flag.insert({i,j});
            if(mp.find({i,j})!=mp.end()){
                cout << mp[{i,j}]-1 << endl;
                break;
            }
        }
    }
}