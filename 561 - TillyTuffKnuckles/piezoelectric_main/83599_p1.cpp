#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;
        int lap = L + W + L + W;
        int lap_gen = R * lap;
        float result = ceil( (float) E / lap_gen);
        cout << result << endl;
    }
    return 0;
}