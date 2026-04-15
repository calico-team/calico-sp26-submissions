#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        long long K,N,M,P,Q;
        cin>>K>>N>>M>>P>>Q;
        vector<pair<long long,long long>> a(K);
        unordered_map<long long,int> mp;
        mp.reserve(K*2);

        for(int i=0;i<K;i++){
            cin>>a[i].first>>a[i].second;
            long long key = a[i].first * (long long)1'000'000'007 + a[i].second;
            mp[key] = i;
        }

        long long x = a[0].first;
        long long y = a[0].second;

        for(long long step=1; step<=N*M; step++){
            x = (x + Q) % N;
            y = (y + P) % M;
            long long key = x * (long long)1'000'000'007 + y;
            auto it = mp.find(key);
            if(it != mp.end()){
                cout<<it->second;
                if(T) cout<<"\n";
                break;
            }
        }
    }
}