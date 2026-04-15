#include <iostream>
#include <vector>
#include <string>
#define int long long

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    int mx = 0; //trackers for max and min voluemes as we go over the sliecs
    int mn = 0;
    for (int z=0; z<N; z++) { //for each slice of the shape (z axis)
        int a=0, b=0; //a and b are counters for #s in each of the two projections
        for (int x=0; x<N; x++) { //then go over the x axis to count how many #s are present in the slice
            if (x<(int)S1[z].size()&&S1[z][x]=='#') a++; //s1 is a #s
            if (x<(int)S2[z].size()&&S2[z][x]=='#') b++; //s2 is b #s
        }
        mx+=a*b;
        //max vol of a slice is ab bc you can have at most a #s in the x direction and b #s in the y direction so you can have at most ab #s in the z direction, so ab is final count per slice for mxvol
        mn+=max(a, b); //min of a slice is max of a and b bc you need to at least consider the overlapping elements to get the min volume, so just take the max of each slice and sum
    }
    return to_string(mx)+" "+to_string(mn);
}
signed main() {
    int T;
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
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
