#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    int arr[100001];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int b = k;
    for(int i = 0; i<n; i++){
        int a = arr[i];
        p -= a;
        if(b == 0){
            p += r;
            b = k;
        }
        if(p < 0){
            cout << "nah i'd lose" << endl;
            return;
        }
        b--;
    }
    cout << "nah i'd win" << endl;
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