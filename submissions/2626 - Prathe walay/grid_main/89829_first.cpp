#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<long long>&a){
    vector<long long> the_two_tower_heights(n);
    for(int i=0;i<n;i++) the_two_tower_heights[i]=a[i];
    for(int iter=0;iter<1000;iter++){
        for(int i=0;i<n;i++){
            vector<long long>v;
            v.push_back(a[i]);
            if(i>0)v.push_back(the_two_tower_heights[i-1]);
            if(i<n-1)v.push_back(the_two_tower_heights[i+1]);
            sort(v.begin(),v.end());
            the_two_tower_heights[i]=v[v.size()/2];
        }
    }
    for(int i=0;i<n;i++)cout<<the_two_tower_heights[i]<<" \n"[i==n-1];
}

void read_your_input(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        solve(n,a);
    }
}

int main(){
    read_your_input();
}
