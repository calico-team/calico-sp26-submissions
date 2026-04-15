#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // �������룬Ӧ�Դ�������
    int T;
    cin >> T;
    while (T--) {
    	int L,W,R,area;
		long long E;
		cin>>L>>W>>E>>R;
	    long long steps_per_lap = 2LL * (L + W);
        long long power_per_lap = steps_per_lap * R;
        long long laps = E / power_per_lap;
        cout << laps << '\n';
    }
    return 0;
}
