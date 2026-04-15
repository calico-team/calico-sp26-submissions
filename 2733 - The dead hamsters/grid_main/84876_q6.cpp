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
        cout << arr[0] << " " << (arr[0]+arr[2])/2 << " " << arr[2] << endl;
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