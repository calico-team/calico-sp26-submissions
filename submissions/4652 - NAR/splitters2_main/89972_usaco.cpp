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
        ll P;
        int A, B;
        cin >> P >> A >> B;
        int nA = 0, nB = 0;
        ll cur = 1;
        for (; nA < A; nA++) {
            if (cur > P) {
                break;
            }
            cur *= 2;
        }
        for (; nB < B; nB++) {
            if (cur > P) {
                break;
            }
            cur *= 3;
        }
        vector<vector<char>> ans(3, vector<char>(666, '.'));
        ans[0][0] = 'v';
        ans[1][0] = '>';
        for (int i = 1; ; i+=2) {
            ans[1][i] = 'S';
            ans[1][i + 1] = '>';
            if (B > 0) {
                if (B > nB) {
                    ans[0][i] = 'X';
                    ans[2][i] = 'X';
                }
                else {
                    if (P >= 2 * cur / 3) {
                        P -= 2 * cur / 3;
                        ans[0][i] = '^';
                        ans[2][i] = 'v';
                    }
                    else if(P >= cur / 3) {
                        P -= cur / 3;
                        ans[0][i] = '^';
                    }
                    else {
                        ans[0][i] = 'X';
                        ans[2][i] = 'X';
                    }
                    cur /= 3;
                }
                B--;
            }
            else if(A > 0) {
                if (A > nA) {
                    ans[0][i] = 'X';
                }
                else {
                    if (P >= cur / 2) {
                        P -= cur / 2;
                        ans[0][i] = '^';
                    }
                    else {
                        ans[0][i] = 'X';
                    }
                    cur /= 2;
                }
                A--;
            }
            else {
                ans[1][i + 2] = 'X';
                break;
            }
        }
        cout << 3 << " " << 666 << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 666; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}