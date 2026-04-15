#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        vector<int>rpta(n);
        rpta[0]=v[0];
        rpta[n-1]=v[n-1];
        for(int i=1;i<n-1;i++){
            vector<int>curr;
            curr.push_back(v[i]);
            curr.push_back(v[i+1]);
            curr.push_back(v[i-1]);
            sort(curr.begin(),curr.end());
            //for(auto x:curr) cout<<x<<" ";
            //cout<<endl;
            rpta[i]=curr[1]; 
        }
        for(auto x:rpta) cout<<x<<" ";
        cout<<endl;
    }

}
