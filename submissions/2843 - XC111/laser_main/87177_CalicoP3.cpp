#include<bits/stdc++.h>
using namespace std;
pair<int, int> a[110];
int main(){
    int T;
    cin >> T;
    while(T--){
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        for(int i = 1; i <= k; i++){
            cin >> a[i].first >> a[i].second;
        }
        int curx = a[1].first;
        int cury = a[1].second;
        bool ans = false;
        while(!ans){
            curx += p;
            cury += q;
            curx %= n;
            cury %= m;
            for(int i = 1; i <= k; i++){
                if(curx == a[i].first && cury == a[i].second){
                    cout << (i-1) << endl;
                    ans = true;
                    break;
                }
            }
        }
    }
    return 0;
}