#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
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
	double laps = 0;
	double perimeter = 2*(L + W);

	double metersNeeded = E/R;

	laps = std::ceil(perimeter/metersNeeded);
	if (laps < 1)
	{
		laps = 1/laps;
	}

	return laps;
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