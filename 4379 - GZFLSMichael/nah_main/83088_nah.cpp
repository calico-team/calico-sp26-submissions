#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >>  a;
    for (int i = 0; i < a; i++){
        int N, P , R ,K;
        cin >> N >> P >> R >> K;
        bool win = true;
        for( int i = 0; i < N; i++){
            int usede;
            cin >> usede;
            if(!win) continue;
            P -= usede;
            if(P < 0) win = false;
            if(i % K == 0) P += R;
        }
        if(win) cout << "nah i’d win";
        else cout << "nah i’d lose";
    }
    return 0;
}