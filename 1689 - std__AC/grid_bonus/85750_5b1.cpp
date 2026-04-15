#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100100;
int arr[N];
int t, n, prv;

bool check(int x) {
    return arr[x - 1] < arr[x] && arr[x] > arr[x + 1] || arr[x - 1] > arr[x] && arr[x] < arr[x + 1];
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> vec;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (i > 2 && check(i - 1)) vec.push_back({abs(arr[i - 1] - arr[i - 2] + arr[i - 1] - arr[i]), i - 1});
        }
        sort(vec.begin(), vec.end(), greater());
        for (pair<int, int> i : vec) {
            if (check(i.second)) arr[i.second] = arr[i.second - 1];
        }
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}