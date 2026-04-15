/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


// #include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <fstream>
#include <set>
#include <tuple>
#include <set>
#include <map>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <utility>
#include <random>
#include <cstdlib>
#include <sstream>
#include <chrono>

#define ABC "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define abc "abcdefghijklmnopqrstuvwxyz"

#pragma GCC optimize("O3,unroll-loops")

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }

    // minimize differences
    // sum of vertial + sum of horizontal

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
