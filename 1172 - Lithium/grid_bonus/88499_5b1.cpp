#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i < n-1; i++) {
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                arr[i] = max(arr[i-1],arr[i+1]);
            }
            if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                arr[i] = min(arr[i-1],arr[i+1]);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }  
}