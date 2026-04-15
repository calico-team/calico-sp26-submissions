#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    int arr[3];
    int b[3];
    int x = 0;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        b[i] = arr[i];
        if(i > 0) x += max(arr[i]-arr[i-1], arr[i-1]-arr[i]);
    }
    sort(arr, arr+n);
    int y = 0;
    for(int i = 0; i<n; i++){
        y += max(arr[i]- arr[n/2], arr[n/2] - arr[i]);
    }
    for(int i = 0; i<n; i++){
        if(x > y){
            cout << arr[n/2];
        }else{
            cout << b[i];
        }
        if(i == n-1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    
    return 0;
}