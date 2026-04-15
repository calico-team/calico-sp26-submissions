#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<int> ax(K), ay(K);
        for(int i = 0; i < K; i++){
            cin >> ax[i] >> ay[i];
        }

        int x = ax[0];
        int y = ay[0];
        bool found = false;

        while(!found){
            x = (x + Q) % N;
            y = (y + P) % M;

            for(int i = 0; i < K; i++){
                if(ax[i] == x && ay[i] == y){
                    cout << i << "\n";
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}
