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
        int N;
        cin >> N;
        vector<string> s1(N), s2 = s1;
        vector<int> cnt1(N, 0), cnt2 = cnt1;
        ll mn = 0, mx = N * N * N;
        for (int i = 0; i < N; i++) {
            cin >> s1[i];
            for (int j = 0; j < N; j++) {
                if (s1[i][j] == '#') {
                    cnt1[i]++;
                }
                else {
                    mx -= N;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            cin >> s2[i];
            for (int j = 0; j < N; j++) {
                if (s2[i][j] == '#') {
                    cnt2[i]++;
                }
                else {
                    mx -= N;
                    mx += N - cnt1[i];
                }
            }
            mn += max(cnt1[i], cnt2[i]);
        }
        cout << mx << " " << mn << endl;
    }
}