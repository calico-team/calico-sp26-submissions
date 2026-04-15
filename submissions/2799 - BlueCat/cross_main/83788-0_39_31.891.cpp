#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        int start = 0;
        int accbegin = 0;
        for(int i = 0; i < N; i++){
            start = accbegin;
            cout << start;
            for(int j = 1; j < M; j++){
                start++;
                if(start == 5) start = 0;
                cout << " " << start;
            }
            accbegin += 3;
            if(accbegin > 4) accbegin -= 5;
            cout << "\n";
        }

    }
}