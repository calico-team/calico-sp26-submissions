#include <bits/stdc++.h>

using namespace std;
void solve() {
    string A, B;
    cin>>A>>B;
    int n = A.size();
    int m = B.size();
    int i = 0, j = 0;
    while(i < n) {
        if(A[i] == B[j]) {
            i++;
            j++;
            cout<<A[i-1];
        } else {
            i++;
            cout<<"#";
        }
    }cout<<endl;
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