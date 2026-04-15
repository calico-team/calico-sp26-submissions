#include <iostream>
#include <vector>
#include <string>
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
	int current_P=P;
	int curses_treated=0;
	for(int i=0;i<N;i++){
		if(curses_treated>=K && current_P>=R){
			current_P=P;
			curses_treated=0;
		}
		current_P -= E[i];
		if(current_P<0)	
		{
			return "Lose";
		}
		curses_treated++; }
    return "Win";
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
    return 0;
}
