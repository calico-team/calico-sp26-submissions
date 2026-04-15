#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
int numOfChar(string S, char c){
     	int j(0);
	for(char i:S){
     		if(i==c)j++;
	}
	return j;
}
int maxSolve(int N, vector<string> S1, vector<string> S2){
	// I'm the world's greatest programer that's why angnes tachyon chose me
	int TotalArea(0);
	for(int i(0);i<N;i++){
     		TotalArea+=N*N - N*(numOfChar(S1[i],'.')+numOfChar(S2[i], '.'))   +   numOfChar(S1[i],'.')*numOfChar(S2[i], '.');
        }
	return TotalArea;
}
int minSolve(int N, vector<string> S1, vector<string> S2) {
	int numOfPairs=0;
	for(int i(0);i<S1.size();i++){
		numOfPairs+=max(numOfChar(S1[i],'#'),numOfChar(S2[i], '#'));
	}
	

	return numOfPairs;
}
string solve(int N, vector<string> S1, vector<string> S2) {
		
	return to_string(maxSolve(N,S1,S2)) + " " + to_string(minSolve(N,  S1,  S2));

}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}
