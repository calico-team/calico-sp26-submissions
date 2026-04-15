/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canHeWin(long long n, long long p, long long r, long long k, vector<int> curses_power){
    long long curses_defeated = 0, power = p;
    for (long long i = 0; i < curses_power.size(); i++){
        power = power - curses_power[i];
        curses_defeated++;
        if (power < 0) {
            return false;
        }
        if (curses_defeated == k) {
            power += r;
            curses_defeated = 0;
        }
        // cout << power << " " << curses_defeated << " " << i << endl;
    }
    return true;
}

int main() {
    long long tests = 0;
    cin >> tests;
    for (long long i = 0; i < tests; i++){
        long long n, p, r, k;
        int power;
        vector<int> curses_power;
        cin >> n >> p >> r >> k;
        for (long long j = 0; j < n; j++){
            cin >> power;
            curses_power.push_back(power);
        }
        if (canHeWin(n, p, r, k, curses_power)) {
            cout << "nah i'd win" << endl;
        }
        else {
            cout << "nah i'd lose" << endl;
        }
        
    }

    return 0;
}