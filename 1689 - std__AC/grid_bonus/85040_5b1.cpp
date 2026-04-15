#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100100;
int arr[N];
int t, n, prv;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++) {
            if (1 < i && i < n && (arr[i - 1] < arr[i] && arr[i] > arr[i + 1] || arr[i - 1] > arr[i] && arr[i] < arr[i + 1])) cout << prv << ' ';
            else {
                cout << arr[i] << ' ';
                prv = arr[i];
            }
        }
        cout << endl;
    }
    return 0;
}