#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[100005];

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v;
		for(int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			arr[i] = a;
		}
		for(int i = 2; i < n; i++) {
			if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
				arr[i] = max(arr[i - 1], arr[i + 1]);
			}
			if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
				arr[i] = min(arr[i - 1], arr[i + 1]);
			}
		}
		for(int i = 1; i <= n; i++) {
			cout << arr[i] << ' ';
		}
			
	}
}

