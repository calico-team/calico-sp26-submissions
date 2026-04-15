#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    pair<int, int> arr[100001];
    for(int i = 0; i<k; i++){
        int x, y;
        cin >> x >> y;
        arr[i].first = x;
        arr[i].second = y;
    }
    int x = arr[0].first;
    int y = arr[0].second;
    while(true){
        x = (x+q)%n;
        y = (y+p)%m;
        for(int i = 0; i<k; i++){
            if(x == arr[i].first && y == arr[i].second){
                cout <<"a" << i << endl;
                return;
            }
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