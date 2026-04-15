#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define f(i, n) for (ll i = 0; i < n; ++i)

// Problem Statement
/*
  
*/

// Small Observations
/*
  
*/

// Claims on Algo
/*
  
*/

void solve() {
    string A, B;
    cin >> A >> B;

    vector<int> impIndexes(B.size());

    int bIndex = 0;
    for(int i=0;i<A.size() && bIndex < B.size(); i++){
            if(A[i] == B[bIndex]){
                impIndexes.push_back(i);
                bIndex++;
            }   
    }

    string result = A;


    for(int i=0;i<result.size();i++){
            result[i] = '#'; 
    }

    for(int i=0;i<impIndexes.size();i++){
            result[impIndexes[i]] = A[impIndexes[i]]; 
    }

    cout << result << endl;



}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}