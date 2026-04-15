/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        
        vector<long long> b(N);
        for (int i = 0; i < N; i++) {
            vector<long long> v;
            v.push_back(a[i]);
            if (i) v.push_back(a[i-1]);
            if (i+1 < N) v.push_back(a[i+1]);
            sort(v.begin(), v.end());
            b[i] = v[v.size()/2];
        }
        
        for (int i = 0; i < N; i++) {
            cout << b[i] << " \n"[i==N-1];
        }
    }
    
    return 0;
}
