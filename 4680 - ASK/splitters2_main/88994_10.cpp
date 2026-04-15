#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

vector<pair<int,int>> buildSteps(ll num, int cnt2, int cnt3) {
    vector<int> fac;
    for (int i = 0; i< cnt2; i++) fac.push_back(2);
    for (int i = 0; i< cnt3; i++) fac.push_back(3);

    int numF = fac.size();
    ll cap = num+1;

    vector<ll> suf(numF+1, 1);
    for (int i = numF-1; i >= 0; i--) {
        if (suf[i+1] > num/fac[i]) {
            suf[i] = cap;
        } else {
            suf[i] = suf[i+1]*fac[i];
        }
    }

    vector<pair<int,int>> steps;
    ll rem = num;

    for (int i = 0; i < numF;i++){
        ll nxtDen = suf[i+1];
        int digit = 0;

        if (nxtDen != cap) {
            digit = rem/ nxtDen;
            rem%=nxtDen;
        }

        steps.push_back({fac[i],digit});
    }

    return steps;
}

vector<string> buildFactory(const vector<pair<int,int>> &steps) {
    int numS = steps.size();
    int numR = 3, numC = 2*numS+1;

    vector<string> grid(numR, string(numC,'.'));
    grid[0][0] = 'v';
    grid[1][0] = '>';

    for (int i = 0; i <numS; i++) {
        int col = 2*i+1;
        int kind = steps[i].first, digit = steps[i].second;

        grid[1][col]='S';
        grid[1][col + 1] =(i + 1 < numS ?'>' : 'X');

        if (kind == 2) {
            grid[0][col] =(digit == 1 ?'^' : 'X');
        } else {
            grid[0][col] =(digit >= 1 ?'^' : 'X');
            grid[2][col] =(digit == 2 ?'v' : 'X');
        }
    }

    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;cin>> T;

    while (T--) {
        ll num;
        int cnt2, cnt3;
        cin>>num>>cnt2>>cnt3;

        vector<pair<int,int>> steps = buildSteps(num, cnt2, cnt3);
        vector<string> grid = buildFactory(steps);

        cout << (int)grid.size() <<' '<< (int)grid[0].size() <<'\n';
        for (string &row: grid) {
            cout <<row<<'\n';
        }
    }
}