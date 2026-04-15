#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<long long>
#define endl "\n"
#define nline cout<<endl
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
    int n,p,r,k;
    cin >> n >> p >> r >> k;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    int i = 0;
    ll gojoPower = p;
    int cursesDefeaCount = 0;

    while(i < n){

        if(cursesDefeaCount > 0 && cursesDefeaCount % k == 0){
            gojoPower += r;
        }


        gojoPower -= a[i];

        if(gojoPower < 0){
            cout << "nah i’d lose" << endl;
            return;
        }

        i++;
        cursesDefeaCount++;
    }

    cout << "nah i’d win" << endl;
   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}