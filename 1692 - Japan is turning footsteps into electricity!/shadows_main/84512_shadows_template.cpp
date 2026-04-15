#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
void solve(int N, vector<string> S1, vector<string> S2) {
    // YOUR CODE HERE
    
    int mn = 0, mx = 0;
    for(int i=0; i<S1.size(); i++){
    	int ct1 = 0, ct2 = 0;
    	for(int j=0; j<S1[i].size(); j++){
    		if(S1[i][j] == '#')ct1++;
    		if(S2[i][j] == '#')ct2++;
		}
		mn += max(ct1, ct2);
	}
	
	for(int i=0; i<S1.size(); i++){
    	int ct1 = 0, ct2 = 0;
    	for(int j=0; j<S1[i].size(); j++){
    		if(S1[i][j] == '#')ct1++;
    		if(S2[i][j] == '#')ct2++;
		}
		mx += ct1*ct2;
	}
	
    cout<<mx<<" "<<mn<<"\n";
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
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
        solve(N, S1, S2);
    }
}
