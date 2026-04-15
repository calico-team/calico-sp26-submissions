#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 300005;
ll A[MAX], M[MAX], ans[MAX];

ll get_median(ll a, ll b, ll c) {
    return a + b + c - max({a, b, c}) - min({a, b, c}); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> A[i];

        M[0] = A[0];
        for (int i = 1; i < n; i++) {
            M[i] = get_median(A[i], A[i - 1], M[i - 1]);
        }

        ans[n - 1] = M[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = get_median(ans[i + 1], A[i], M[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}