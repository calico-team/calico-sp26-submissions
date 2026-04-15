#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        vector<int>rpta(n);
        for(int i=2;i<n;i++){
            vector<int>curr;
            for(int j=i;j>i-3;j--) curr.push_back(v[j]);
            sort(curr.begin(),curr.end());
            /*for(auto x:curr) cout<<x<<" ";
            cout<<endl;*/
            for(int j=i;j>i-3;j--) rpta[j]=curr[1]; 
        }
        for(auto x:rpta) cout<<x<<" ";
        cout<<endl;
    }

}
