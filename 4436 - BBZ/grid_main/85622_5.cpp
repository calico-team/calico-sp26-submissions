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
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        nth_element(arr,arr+n/2,arr+n);
        for(int i=0;i<n;i++){
            cout << arr[n/2] << " ";
        }
        cout << endl;
    }
}