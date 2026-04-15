#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
typedef long long ll;
int main() {
    int T; cin>>T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n, 0);
        vector<ll> L(n, 0);
        vector<ll> R(n, 0);
        vector<ll> b(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        L[0] = a[0];
        R[0] = a[0];
        for (int i = 1;i<n;i++){
            if (a[i] < L[i - 1]) {
                L[i]=a[i];
                R[i]=L[i - 1];
            } else if (a[i] > R[i - 1]) {
                L[i] = R[i - 1];
                R[i]=a[i];
            } else {
                L[i] = a[i];
                R[i] = a[i];
            }
        }

        b[n - 1] = L[n - 1];
        for (int i = n - 2; i > -1; i--) {
            b[i] = min(R[i], max(L[i], b[i + 1]));
        }

        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        printf("\n");
    }
}