#include <bits/stdc++.h>
using namespace std;
string solve(string A, string B) {
    int j=0;
    for(int i=0; i<(int)A.size(); i++) {
        if(j<(int)B.size()&&A[i]==B[j]) {
            j++;
        } else {
            A[i]='#';
        }
    }
    return A;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        string A, B;
        cin>>A>>B;
        cout<<solve(A, B)<<'\n';
    }
    return 0;
}