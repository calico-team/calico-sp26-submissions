#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    long long mx=0,mn=0;

    for(int i=0;i<N;i++){
        int c1=0,c2=0;

        for(char c:S1[i])if(c=='#')c1++;
        for(char c:S2[i])if(c=='#')c2++;
        mx+=1LL*c1*c2;
        mn+=max(c1,c2);
    }

    return to_string(mx)+" "+to_string(mn);
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
