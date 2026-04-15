#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<long long>&a){
    vector<long long> th(n);
    for(int i=0;i<n;i++) th[i]=a[i];
    for(int i=0;i<n;i++) cout<<th[i]<<" \n"[i==n-1];
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
