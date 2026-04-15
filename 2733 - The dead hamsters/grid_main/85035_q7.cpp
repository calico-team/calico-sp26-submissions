#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    int arr[3];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    if(n == 1){
       cout << arr[0] << endl;
       return;
    }
    if(n == 2){
        cout << arr[0] << " " << arr[1] << endl;
        return;
    }
    if(n == 3){
        int b = (arr[0]+arr[2])/2;
        if(arr[0] > arr[1]);
        b = (arr[0] + arr[2] + 1)/2;
        cout << arr[0] << " " << b << " " << arr[2] << endl;
        return;
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