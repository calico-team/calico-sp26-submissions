#include <iostream>
#include <vector>
#define int long long
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
    int p = P; int c = 0;
    for (int i=0; i<N; i++) {
        if (K>0&&c>0&&c%K==0) p+=R; //if cd is up reset power
        p-=E[i]; //gojo smacking the curse
        if (p<0) return "nah i'd lose"; //if his power <0 then he loses
        c++; //keep track to know when to reset
    }
    return "nah i'd win"; //if he kills all of them then he wins
}

signed main() {
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
