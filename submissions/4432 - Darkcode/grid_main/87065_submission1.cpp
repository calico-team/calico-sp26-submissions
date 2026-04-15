#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // find median
        vector<long long> temp = arr;
        sort(temp.begin(), temp.end());
        long long median = temp[n / 2];

        // make all elements = median
        for (int i = 0; i < n; i++) {
            cout << median;
            if (i != n - 1) cout << " ";
        }

        cout << "\n";
    }

    return 0;
}