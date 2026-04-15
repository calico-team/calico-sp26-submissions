#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<vector<string>> S1, vector<vector<string>> S2) {
    
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<vector<string>> S1(N);
        for (int i = 0; i < N; i++) {
            for(int j = 0;j<N;j++){
                string s;
                cin >> s;
                S1[i].push_back(s);
            }
        }
        vector<vector<string>> S2(N);
        for (int i = 0; i < N; i++) {
            for(int j = 0;j<N;j++){
                string s;
                cin >> s;
                S2[i].push_back(s);
            }
        }
        //cout << solve(N, S1, S2) << '\n';
        vector<vector<vector<bool>>> maxVolume(N, vector<vector<bool>>(N, vector<bool>(N, true)));
        vector<vector<vector<bool>>> minVolume(N, vector<vector<bool>>(N, vector<bool>(N, false)));


        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(S1[i][j] == "."){
                    for(int k = 0;k<N;k++){
                        maxVolume[i][j][k] = false;
                    }
                }
                else{
                    minVolume[i][j][0] = true;
                }
            }
        }
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(S2[i][j] == "."){
                    for(int k = 0;k<N;k++){
                        maxVolume[k][j][i] = false;
                    }
                }
                else{
                    minVolume[0][j][i] = true;
                }
            }
        }

        //calculate volume of minVolume
        int minVolumeCount = 0;
        for(int i = 0;i<N;i++){
            bool removed = false;
            for(int j = 0;j<N;j++){
                int k;
                for(k = 0;k<N-1;k++){
                    if(minVolume[i][j][k] == true){
                        minVolumeCount++;
                    }

                }
            }
        }

        int maxVolumeCount = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                for(int k = 0;k<N;k++){
                    if(maxVolume[i][j][k] == true){
                        maxVolumeCount++;

                    }
                }
            }
        }

        cout << maxVolumeCount << " " << minVolumeCount << endl;
    }
}
