#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int,int>>;
using vvi = vector<vector<int>>;
using pi = pair<int,int>;
void solve() {
    int N,M,D;cin>>N>>M>>D;
    vi A(N,0);
    vvi B;
    int i=1;
    while (M--){
        int R,C,V,W;
        cin>>R>>C>>V>>W;
        B.push_back({1000-W,R-1,C-1,V,i});
        i++;
    }
    sort(B.begin(),B.end());
    vector<pair<double,int>> error;
    for (vi info:B){
        int W = 1000-info[0];
        int R = info[1];
        int C = info[2];
        int V = info[3];
        int i = info[4];
        if (A[C]==0 && A[R]==0){
            A[C] = sqrt(V);
            A[R] = round(V/(A[C]));
        }
        else if (A[C]==0){
            A[C] = round(V/(A[R]));
        }
        else if (A[R]==0){
            A[R] = round(V/(A[C]));
        }
        double thisError = abs(A[C]*A[R]-V)*W/V;
        error.push_back({thisError,i}); 
    }
    sort(error.begin(),error.end());
    reverse(error.begin(),error.end());
    cout<<A[0];
    for (int i=1;i<N;i++){
        cout<<" "<<A[i];
    }
    cout<<"\n";
    cout<<D;
    int count = 0;
    for (pair<double,int> thisErr:error){
        if (count>=D)break;
        cout<<" "<<thisErr.second;
        count++;
    }
    cout<<"\n";
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}