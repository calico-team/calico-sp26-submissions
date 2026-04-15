#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e18;
int N;
vector<string> A, B;
void docase(){
    cin >> N;
    A = B = vector<string>(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    int o1 = N*N*N, o2 = 0;
    for (int i = 0; i < N; i++){
        int p = 0, q = 0;
        for (int j = 0; j < N; j++) {
            if (A[i][j] == '.') {
                p++;
            }
            if (B[i][j] == '.') {
                q++;
            }
        }
        o1 -= p * N + q * N - p * q;
        o2 += max(N-p, N-q);
    }
    cout << o1 << ' ' << o2 << '\n';
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