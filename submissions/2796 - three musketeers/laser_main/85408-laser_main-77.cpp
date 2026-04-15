#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;


int main() {
	int T; cin >> T;

	while (T--) {
		int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		// vector<int> X(K), Y(K);
        int cx = 0;
        int cy = 0;
        vector<vector<pair<bool, int> > > arr(N, vector<pair<bool, int> >(M, {false, 0}));
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
            if(i == 0){
                cx = a;
                cy = b;
            }
			// X[i] = a;
			// Y[i] = b;
            arr[a][b].first = true;
            arr[a][b].second = i;
		}
        while(true){
            cx = (cx + Q)%N;
            cy = (cy+P)%M;
            if(arr[cx][cy].first){
                cout<<arr[cx][cy].second<<"\n";
                break;
            }
        }
	}
	return 0;
}
