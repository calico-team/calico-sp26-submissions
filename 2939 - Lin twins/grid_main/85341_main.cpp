/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


#include <bits/stdc++.h>
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

long long calcCost(vector<long long>& A, vector<long long>& B, int N) {
    long long cost = 0;
    
    for (int i = 0; i < N - 1; ++i) cost += abs(A[i] - A[i+1]);
    
    for (int i = 0; i < N - 1; ++i) cost += abs(B[i] - B[i+1]);
    
    for (int i = 0; i < N; ++i) cost += abs(A[i] - B[i]);
    
    return cost;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }

    // minimize differences
    // sum of vertial + sum of horizontal

    vector<long long> b1 = arr;
    long long c1 = calcCost(arr, b1, n);
    
    vector<long long> temp = arr;
    vector<long long> b2(n);
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++) {
        b2[i] = temp[n/2];
    }

    long long c2 = calcCost(arr, b2, n);
    vector<long long> b3(n);

    if(c1 <= c2) {
        b3 = b1;
    } else {
        b3 = b2;
    }
    
    for (int i = 0; i < n; i++) {
        cout << b3[i] << " ";
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
