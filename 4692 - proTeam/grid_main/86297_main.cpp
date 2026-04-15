#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<long> ligma(N);

        for (int i = 0; i < N; i++) {
            cin >> ligma[i];
        }

        for (int i = 0; i < N; i++) {
            cout << ligma[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

