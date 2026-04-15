#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    long long P, R, K;
    cin >> N >> P >> R >> K;

    vector<long long> E(N);
    for (int i = 0; i < N; ++i){
        cin >> E[i];
    }

    long long powerlol = P;
    bool gojonooo = false;

    for (int i = 0; i < N; ++i){
        powerlol -= E[i];

        if(powerlol < 0){
            gojonooo = true;
            break; 
        }

        if ((i + 1) % K == 0){
            powerlol += R;
        }
    }

    if(gojonooo){
        cout << "nah i'd lose"<<"\n";
    } else {
        cout << "nah i'd win"<<"\n";
    }
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
