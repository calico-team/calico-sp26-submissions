#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXK=100005;
ll ast[MAXK][2];
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int K;
        ll N,M,P,Q;
        cin>>K>>N>>M>>P>>Q;
        for(int i=0;i<K;i++)cin>>ast[i][0]>>ast[i][1];
        ll cx=ast[0][0],cy=ast[0][1];
        int ans=0;
        map<pair<ll,ll>,int>mp;
        for(int i=0;i<K;i++)mp[ast[i][0]*10000000+ast[i][1]]=i;
        while(1){
            cx=(cx+Q)%N;
            cy=(cy+P)%M;
            if(mp.count(cx*10000000+cy)){
                ans=mp[cx*10000000+cy];
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
