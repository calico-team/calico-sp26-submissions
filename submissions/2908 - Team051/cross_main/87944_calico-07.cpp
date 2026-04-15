#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int N,M; cin >> N >> M;
        for(int i=0;i<N;i++){
            for(int j=1;j<=M;j++){
                cout << (j+2*i)%5 << " ";
            }
            cout << endl;
        }
    }
}
