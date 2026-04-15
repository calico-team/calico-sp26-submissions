#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

char c[N][N], d[N][N];

int cnt[N];

int n, t, mx, mn;

int main(){

    cin >> t;

    while(t --){

        cin >> n;

        mx = n * n * n, mn = 0;
        
        for(int i = 1; i <= n; i ++){
            cnt[i] = 0;
            for(int j = 1; j <= n; j ++){
                cin >> c[i][j];
                cnt[i] += c[i][j] == '.';
                mx -= (c[i][j] == '.') * n;
            }
        }

        for(int i = 1; i <= n; i ++){
            int cnt2 = 0;
            for(int j = 1; j <= n; j ++){
                cin >> d[i][j];
                cnt2 += (d[i][j] == '#');
                if(d[i][j] == '.') mx -= n - cnt[i];
            }
            mn += max(cnt2, n - cnt[i]);
        }

        cout << mx << ' ' << mn << endl;

    }

    return 0;
}

