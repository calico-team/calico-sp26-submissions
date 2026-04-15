#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    long long maxnum=0,minnum=0;
    for(int z=0;z<N;z++){
    	int xcnt=0,ycnt=0;
    	for(int y=0;y<N;y++){
    		if(S1[z][y]=='#'){
    			ycnt++;
			}
		}
    	for(int x=0;x<N;x++){
    		if(S2[z][x]=='#'){
    			xcnt++;
			}
		}
		maxnum+=xcnt*ycnt;
		if(xcnt>ycnt){
			minnum+=xcnt;
		}
		else{
			minnum+=ycnt;
		}
	}
	stringstream ss1,ss2;
	ss1<<maxnum;
	ss2<<minnum;
	return ss1.str()+" "+ss2.str();
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
