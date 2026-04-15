#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int,int>>;
using vvi = vector<vector<int>>;
using pi = pair<int,int>;
void solve() {
    int N;cin>>N;
    vi A(N);
    for (int i=0;i<N;i++){
        cin>>A[i];
    }
    vi B(N);
    B[0]=A[0];
    B[N-1]=A[N-1];
    for (int i=1;i<N-1;i++){
        if (A[i]>A[i-1] && A[i]>A[i+1]){
            B[i] = max(A[i-1],A[i+1]);
        }
        else if (A[i]<A[i-1] && A[i]<A[i+1]){
            B[i]=min(A[i-1],A[i+1]);
        }
        else{
            B[i]=A[i];
        }
    }
    for (int i=0;i<N-1;i++){
        cout<<B[i]<<" ";
    }
    cout<<B[N-1]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;cin>>T;
    while (T--)solve();
    return 0;
}