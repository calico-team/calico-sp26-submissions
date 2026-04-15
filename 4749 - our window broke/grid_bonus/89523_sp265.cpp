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
        // for(int i=0;i<n;i++){
        //     cout << hm << " ";
        // }
        int total1=0,total2=0,total3=0;
        for(int i=0;i<n;i++){
            total1 += abs(hm-a[i]);
        }for(int i=1;i<n;i++){
            total2 += abs(a[i]-a[i-1]);
        }
        if(total1 + total2<=total2 + total2){
            for(int i=0;i<n;i++){
              cout << hm << " ";
            }
        }else{
            for(int i=0;i<n;i++){
              cout << a[i] << " ";
            }
        }
        cout << endl;
    }
}