#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> arr(N);
        for (int& i : arr) {
            cin >> i;
        }
        sort(arr.begin(), arr.end());
        int flag = 1;
        for (int i = 0; i < N; ++i) {
            P -= arr[i];
            if (P < 0) {
                flag = 0;
                break;
            }
            if (i % K == K - 1) {
                P += R;
            }
        }
        if (flag) {
            cout << "nah i’d win\n";
        }
        else {
            cout << "nah i’d lose\n";
        }
    }
}