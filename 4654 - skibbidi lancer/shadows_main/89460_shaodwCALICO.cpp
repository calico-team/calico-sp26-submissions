#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    ll vlmin =0, vlmax = 0, bl1, bl2;
    for(int x = 0; x < N; x++){
        bl1 = 0, bl2 = 0;
        for(int y = 0; y< N; y++){
            cout << S1[x][y]<< S2[x][y];
            if(S1[x][y] == '#'){bl1++;}
            if(S2[x][y] == '#'){bl2++;}
        }
        vlmin += max(bl1, bl2);
        vlmax += bl1 * bl2;
    }
    cout << vlmax << " " << vlmin;
    return "";
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
