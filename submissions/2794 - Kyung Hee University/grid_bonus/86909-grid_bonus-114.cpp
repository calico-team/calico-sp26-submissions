#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 1; i + 1 < N; i++) {
            if (A[i - 1] < A[i] && A[i + 1] < A[i]) A[i] = max(A[i - 1], A[i + 1]);
            else if (A[i - 1] > A[i] && A[i + 1] > A[i]) A[i] = min(A[i - 1], A[i + 1]);
        }

        for (int i = 0; i < N; i++) cout << A[i] << ' ';
        cout << '\n';
    }
}