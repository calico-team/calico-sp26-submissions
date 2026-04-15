#include <bits/stdc++.h>
using namespace std;
void solve(){
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<pair<int, int>> arr;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    int curx = arr[0].first;
    int cury = arr[0].second;
    while(true){
        curx += q;
        cury += p;
        if(curx >= n){
            curx -= n;
        }
        if(cury >= m){
            cury -= m;
        }
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].first == curx and arr[i].second == cury){
                cout << i << endl;
                return;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}