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
    int sumPower = 0;

	for(int i: E){
        sumPower += i;
    }
    if(P >= sumPower){
        return "nah i'd win";
    }
    for(int x = 0; x < N; x++){
        if(E[x] > P){
            return "nah i'd lose";
        }
        else{
            P -= E[x];
            if((x+1)%K == 0){
             P += R;
            }
            if(P <= 0){
                return "nah i'd lose";
            }
        }
        if((x+1)%K == 0){
            P += R;
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
