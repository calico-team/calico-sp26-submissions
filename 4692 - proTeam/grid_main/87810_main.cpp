#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<long long> ligma(N);

        for (int i = 0; i < N; i++){
            cin >> ligma[i];
        }

        for (int i = 0; i < N; i++) {
            if (i == 0 || i == N-1) {
                cout << ligma[i];
            } else {
                cout << max(min(ligma[i-1], ligma[i+1]), min(max(ligma[i-1], ligma[i+1]), ligma[i]));
            }
            if (i + 1 < N) {
                cout << ' ';
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}

