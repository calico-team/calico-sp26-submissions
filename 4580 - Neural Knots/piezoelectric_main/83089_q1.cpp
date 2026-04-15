#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");

	int T; cin >> T;
	while (T--) {
		int L, W, E, R; 
		cin >> L >> W >> E >> R;
		int perimeter = 2 * (L + W);
		int energy_per_lap = perimeter * R;
		int laps = E / energy_per_lap;                                                                                                                                                                 
		cout << laps << endl;
	}
	return 0;

    // fin.close();
    // fout.close();
    return 0;
}

