#include <bits/stdc++.h>

using namespace std;

#define ll long long 

/**
 * Output whether Gojo will win the fight.
 * 
 * N: Number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */
string solve(int N, ll P, ll R, int K, vector<int> E) {
	// YOUR CODE HERE
	
	int ko = 0;
	for ( int i = 0; i<N; i++){
		P -= E[i];
		if(P<0) return "nah i’d lose";
		ko++;
		if(ko%K==0){
			
			P+= R;
			
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
