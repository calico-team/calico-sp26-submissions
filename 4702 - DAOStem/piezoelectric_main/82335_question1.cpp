
#include <bits/stdc++.h>
using namespace std;

int solve(int L, int W, int E, int R) {
	
	long long int perimeter = (2*L) + (2*W);
	long long int energyperlap = perimeter * R;
	int energy = 0;
	int totallaps = 0;
	while(energy < E){
	    energy = energy + energyperlap;
	    totallaps++;
	}
	
	return totallaps; 
}


int main() {
	int T; cin >> T;
	while (T--) {
		int L, W, E, R; 
		cin >> L >> W >> E >> R;

		cout << solve(L, W, E, R) << endl;
	}
	return 0;
}