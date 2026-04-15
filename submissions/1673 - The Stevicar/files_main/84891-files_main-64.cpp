#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    */
    int lenA = A.length();
    int lenB = B.length();

    vector<int> safeIndices;

    int j = 0;

    for (int i = 0; i < lenB; i++)
    {
        for (j; j < lenA; j++)
        if ((B[i] == A[j]) && (A[j] != A[j+1]))
        {
            safeIndices.push_back(j);
            break;
        }
    }

    for (int i = 0, j = 0; i < lenA; i++)
    {
        if (i != safeIndices[j])
        {
            A[i] = '#';
        }
        else
        {
            j++;
        }
    }
    
    return A;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}