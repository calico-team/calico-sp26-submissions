#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e18;
int N, M;
void docase(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (i+2*j)%5;
            if (j == M-1) cout << '\n';
            else cout << ' ';
        }
    }
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 0 ; i < tt; i++){
        docase();
    }
    return 0;
}