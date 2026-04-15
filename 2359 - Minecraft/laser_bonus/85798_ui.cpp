#include <bits/stdc++.h>
using namespace std;

void solve() {
    int K;
    long long N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;

    vector<pair<long long, long long>> a(K);
    for (int i = 0; i < K; ++i){
        cin >> a[i].first >> a[i].second;
    }

    long long x = a[0].first;
    long long y = a[0].second;
    long long s = N * M;

    for (long long t = 1; t <= s; ++t){
        x = (x + Q) % N;
        y = (y + P) % M;
        
        int f = -1;
        for (int i = 0; i < K; ++i){
            if (x == a[i].first && y == a[i].second){
                f = i;
                break;
            }
        }
        
        if (f != -1){
            cout << f << "\n";
            return;
        }
    }
    
    cout << 0 << "\n";
}

int main() {
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    
    return 0;
}
