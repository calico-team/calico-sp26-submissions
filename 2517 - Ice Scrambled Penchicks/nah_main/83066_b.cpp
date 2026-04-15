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
    string win = "nah i'd win";
    string lose = "nah i'd lose";
    //n number of curses
    //p gojo's power
    //r amount of power reverse cursed restores
    //k number of curses he needs to defeat before he can use the reverse curse technique again
    
    int goho_hp = P;
    //int streak = 0;
    
    for(int i= 0;i<E.size(); i++){
        goho_hp -= E[i];

        if(goho_hp < 0){
            break;
        }
        //every kth
        if((i+1)%K == 0){
            goho_hp += R;
            //restore
        }

    }


    if(goho_hp >= 0){
        return win;
        //cout << win << "\n";
    }
    else{
        return lose;

        //cout << lose << "\n";
    }
    //return "";
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
        cout << solve(N, P, R, K, E) << "\n";
        //cout << solve(N, P, R, K, E) << '\n';
    }
}
