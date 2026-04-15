#include <iostream>
#include <map>
#include <utility>
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
using namespace std;

int main() { FASTIO;
    int t; // # of test cases
    cin >> t;
    while (t--) {
        int n; // dimensions of the cube
        cin >> n;
        char s1[n][n], s2[n][n];
        map<int, int> mp1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> s1[i][j];
                if (s1[i][j] == '#') mp1[i]++;
            }
        }
        map<int, int> mp2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> s2[i][j];
                if (s2[i][j] == '#') mp2[i]++;
            }
        }
        int max_volume = 0, min_volume = 0;
        for (int i = 0; i < n; i++) {
            max_volume += mp1[i] * mp2[i];
            min_volume += max(mp1[i], mp2[i]);
        }

        cout << max_volume << " " << min_volume << endl;
    }
    return 0;
}