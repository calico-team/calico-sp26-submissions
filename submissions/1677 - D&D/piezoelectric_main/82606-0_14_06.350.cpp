#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        long long L,W,E,R;
        cin>>L>>W>>E>>R;
        long long p = 2*(L+W);
        long long lap = p*R;
        cout<<(E/lap);
        if(T) cout<<"\n";
    }
}