#include <bits/stdc++.h>

using namespace std;
void solve() {
   int N,P,R,K;
    cin>>N>>P>>R>>K;
    vector<int> E(N);
    int noOfDefCurses=0;
    for(int i=0;i<N;i++){
        cin>>E[i];
    }
    for(int i=0;i<N;i++){
        if(P>=0){
            P-=E[i];
            noOfDefCurses++;
        }
        
        if(P<0){
            cout<<"nah i'd lose"<<endl;
            return;
        }
        if(noOfDefCurses==K){
            P+=R;
            noOfDefCurses=0;
        }
    }
    cout<<"nah i'd win"<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}