#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int N;
    cin>>N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
 
    vector<long long> L(N), R(N);
    L[0] = A[0];
    R[0] = A[0];
    for (int i = 1; i < N; i++){
        if (A[i] < L[i-1]) {
            L[i] = A[i];
            R[i]= L[i-1];
        } else if (A[i] > R[i-1]) {
            L[i]=R[i-1];
            R[i] = A[i];
        } else {
            L[i] =A[i];
            R[i] = A[i];
        }
    }
    
    vector<long long> b(N);
    b[N-1] = L[N-1]; 
    
    for (int i = N - 2; i >= 0; i--){
        b[i] = max(L[i], min(b[i+1], R[i]));
    }
    for (int i = 0; i < N; i++) {
        cout << b[i] << (i == N - 1 ? "" : " ");
    }
    cout <<"\n";
}


int main(){
    
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}