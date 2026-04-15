//
//  main.cpp
//  测试II
//
//  Created by Kevin on 2024/12/8.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int solve(int L, int W, int E, int R) {
    int a=R*(L+W)*2;
    return E/a;
}


int main() {
    int T; cin >> T;
    while (T--) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;

        cout << solve(L, W, E, R) << endl;
    }
    return 0;
}
