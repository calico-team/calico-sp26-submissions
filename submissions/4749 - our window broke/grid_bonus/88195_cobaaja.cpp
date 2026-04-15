#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int hm;
        if(a.size()%2==1){
            hm = a[a.size()/2];
        }else{
            hm = (a[a.size()/2]+a[a.size()/2 + 1])/2;
        }
        for(int i=0;i<n;i++){
            cout << hm << " ";
        }
        cout << endl;
    }
}