#include <iostream>
#include <vector>

using namespace std;

/**
 * Output whether Gojo will win the fight.
 * 
 * N: Number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */
string solve(int N, int P, int R, int K, vector<int> E) {
	// YOUR CODE HERE
	long long cursed_energy = P;
	int kills = 0;
	bool RCT = false;
	for(int i = 0; i < N; i++){
	    if(RCT && kills >= K){
	        cursed_energy += R;
	        kills = 0;
	        RCT = false;
	    }
	    cursed_energy -= E[i];
	    if(cursed_energy < 0){
	        return "nah i'd lose";
	    }
	    kills++;
	    if(!RCT && kills >= K){
	        RCT = true;
	    }
	}
    return "nah i'd win";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, P, R, K;
		cin >> N >> P >> R >> K;
		vector<int> E(N);
		for (int j = 0; j < N; j++) {
			cin >> E[j];
		}
        cout << solve(N, P, R, K, E) << '\n';
    }
}
