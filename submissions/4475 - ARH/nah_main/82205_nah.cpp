#include <iostream>
#include <vector>

using namespace std;

/**
 * Output whether Gojo will win the fight.
 * 
 * n: number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */
string solve(int n, int P, int R, int K, vector<int> E) {
	int i;
    int count = 0;
    for(i = 0; i < n; ++i){
        if(count == K){
            P+=R;
            count = 0;
        }
        if(P >= E[i]){
            P-=E[i];
        }else{
            return "nah i'd lose";
        }
        ++count;
    }
    return "nah i'd win";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, P, R, K;
		cin >> n >> P >> R >> K;
		vector<int> E(n);
		for (int j = 0; j < n; j++) {
			cin >> E[j];
		}
        cout << solve(n, P, R, K, E) << '\n';
    }
}
