#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long> a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        for(int i=0;i<n;i++){
            cout<<a[i];
            if(i+1<n)cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}