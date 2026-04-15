#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <math.h>
#include <queue>
#include <iomanip>
#include <map>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <bitset>
#include <cstdint>
#include <assert.h>
#include <limits.h>
#include <unordered_map>
#include <memory>
#include <istream>
#include <deque>

using ll = long long;

using namespace std;

int main() {
    //ifstream cin("a.in");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        bool no = 0;
        for (int i = 0; i < N; i++) {
            int E;
            cin >> E;
            if (i % K == 0 && i != 0) {
                P += R;
            }
            P -= E;
            if (P < 0) {
                no = 1;
            }
        }
        if (no) {
            cout << "nah i’d lose" << endl;
        }
        else {
            cout << "nah i’d win" << endl;
        }
    }
}