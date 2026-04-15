#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100100;
int arr[N];
int t, n, prv;

bool check(int n){
    for (int i=1; i<n; ++i){
        if (arr[i]>arr[i-1] && arr[i]>arr[i+1]) return false;
        if (arr[i]<arr[i-1] && arr[i]<arr[i+1]) return false;
    }
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> vec;
        while (!check(n)){
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (i > 2 && arr[i - 2] < arr[i - 1] && arr[i - 1] > arr[i] || arr[i - 2] > arr[i - 1] && arr[i - 1] < arr[i]) vec.push_back({abs(arr[i - 1] - arr[i - 2] + arr[i - 1] - arr[i]), i - 1});
        }
        sort(vec.begin(), vec.end(), greater());
        for (pair<int, int> i : vec) {
            if (arr[i.second - 1] < arr[i.second] && arr[i.second] > arr[i.second + 1]) arr[i.second] = max(arr[i.second - 1], arr[i.second + 1]);
            else if (arr[i.second - 1] > arr[i.second] && arr[i.second] < arr[i.second + 1]) arr[i.second] = min(arr[i.second - 1], arr[i.second + 1]);
        }}
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}