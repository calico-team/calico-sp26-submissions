#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        int N,K;
        long long P,R;
        cin>>N>>P>>R>>K;
        vector<long long> E(N);
        for(int i=0;i<N;i++) cin>>E[i];
        long long cur=P;
        bool ok=true;
        for(int i=0;i<N;i++){
            cur-=E[i];
            if(cur<0){ ok=false; break; }
            if((i+1)%K==0) cur+=R;
        }
        if(ok) cout<<"nah i’d win";
        else cout<<"nah i’d lose";
        if(T) cout<<"\n";
    }
}