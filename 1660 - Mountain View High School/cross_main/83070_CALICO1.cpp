#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int,int>>;
using vvi = vector<vector<int>>;
using pi = pair<int,int>;
void solve() {
    int M,N;cin>>N>>M;
    for (int i=0;i<N;i++){
        int lead = i*2%5;
        cout<<lead;
        for (int j=1;j<M;j++){
            int k=(j+lead)%5;
            cout<<" "<<k;
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;cin>>T;
    while (T--)solve();
    return 0;
}