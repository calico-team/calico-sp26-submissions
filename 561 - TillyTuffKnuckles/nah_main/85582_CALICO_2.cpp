#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> attacks(N);
        for(int b = 0; b < N; b++)
        {
            cin >> attacks[b];
        }
        int energy = P;
        bool lost = false;
        for(int a = 0; a < N; a++)
        {
            energy -= attacks[a];
            if(energy < 0)
            {
                cout << "nah i'd lose" << endl;
                lost = true;
                break; 
            }
            if((a + 1) % K == 0)
            {
                energy += R;
            }
        }
        if(!lost) {
            cout << "nah i'd win" << endl;
        }
    }
    return 0;
}