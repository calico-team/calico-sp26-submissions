/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            vector<ll> v;
            v.push_back(a[i]);
            if (i > 0) v.push_back(a[i-1]);
            if (i < n-1) v.push_back(a[i+1]);
            sort(v.begin(), v.end());
            b[i] = v[(v.size() - 1) / 2];
        }
        
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n-1];
        }
    }
    
    return 0;
}