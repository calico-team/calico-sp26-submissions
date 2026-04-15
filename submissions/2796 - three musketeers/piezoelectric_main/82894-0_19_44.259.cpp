#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
using namespace std;
#define int long long
signed main() {
    int t;
    cin>>t;
    while(t--){
        int w, l, total, r;
        cin>>w>>l>>total>>r;
        cout<<total/(r*(2*w+2*l))<<"\n";
    }

}