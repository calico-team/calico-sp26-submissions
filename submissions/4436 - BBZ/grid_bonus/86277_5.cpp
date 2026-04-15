#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll arr[n],arr1[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        ll costA=0,costB=0;
        for(int i=1;i<n;i++){
            costA+=abs(arr[i]-arr[i-1]);
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            costB+=abs(arr[i]-arr[n/2]);
        }
        if(costB<costA){
            for(int i=0;i<n;i++){
                cout << arr[n/2] << " ";
            }
        }
        else{
            for(int i=0;i<n;i++){
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}