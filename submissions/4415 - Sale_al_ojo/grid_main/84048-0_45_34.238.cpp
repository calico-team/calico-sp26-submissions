#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        for(auto x:v) cout<<x<<" ";
        cout<<endl;
    }

}
