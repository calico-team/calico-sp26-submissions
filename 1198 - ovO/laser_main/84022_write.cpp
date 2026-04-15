#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int K, n, m, p, q, t;

struct str{
    int x, y;
}a[N];

int vx[N], vy[N], cnt1, cnt2;

map <pair <int, int>, int> mp;

int gcd(int x, int y){
    if(!y) return x;
    return gcd(y, x % y);
}

int main(){

    cin >> t;

    while(t --){

        cin >> K >> n >> m >> p >> q;
        int tmp = gcd(p, q);
        p /= tmp, q /= tmp;
        swap(n, m);
        mp.clear();
        for(int i = 1; i <= K; i ++){
            cin >> a[i].x >> a[i].y;
            mp[{a[i].x, a[i].y}] = i - 1;
        }

        // cnt1 = cnt2 = 0;
        // for(int i = 1, j = a[1].x; i <= n; i ++, j = (j + p) % n){
        //     if(i != 1 && j == a[1].x) break;
        //     vx[++ cnt1] = j;
        // }

        // for(int i = 1, j = a[1].y; i <= m; i ++, j = (j + q) % m){
        //     if(i != 1 && j == a[1].y) break;
        //     vy[++ cnt2] = j;
        // }

        for(int i = 1, x = a[1].x, y = a[1].y; i <= n * m; i ++, x = (x + p) % n, y = (y + q) % m){
            // cout << x << ' ' << y << " / ";
            if(i != 1 && mp.count({x, y})){
                cout << mp[{x, y}] << '\n';
                break;
            }
        }

    }

    return 0;
}

