#include <iostream>
typedef long long ll;
using namespace std;

/** 
 * Return the number of laps needed to charge the car (rounded up)
 * 
 * L: Length of car
 * W: Width of car
 * E: Amount of electricity to generate
 * R: Electricity generated per unit distance
 */
int solve(int L, int W, int E, int R) {
	// YOUR CODE HERE
	 
    int rect_Perimeter = 2 * (L + W);
    int energy_Per_Lap = rect_Perimeter * R;
    
    int laps = E / energy_Per_Lap;
    
    return laps;
}
	return 0;
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