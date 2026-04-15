#include<bits/stdc++.h>
using namespace std;

string solve(int N, int P, int R, int K, vector<int>& E){
    int dylan_power = P;
    for(int i=0;i<N;i++){
        dylan_power -= E[i];
        if(dylan_power < 0) return "nah i'd lose";
        if((i+1) % K == 0) dylan_power += R;
    }
    return "nah i'd win";
}

void read_your_input(){
    int T;
    cin>>T;
    while(T--){
        int N,P,R,K;
        cin>>N>>P>>R>>K;
        vector<int> E(N);
        for(int i=0;i<N;i++) cin>>E[i];
        cout<<solve(N,P,R,K,E)<<"\n";
    }
}

int main(){
    read_your_input();
    return 0;
}
