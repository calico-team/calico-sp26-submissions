#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    vector<int> results;
    cin >> T;
    while(T--){
        bool hit = false;
        int xPos, yPos;
        int K, xLimit, yLimit, P, Q;
        cin >> K >> xLimit >> yLimit >> P >> Q;
        vector<int> asteroidX(K);
        vector<int> asteroidY(K);
        for(int i = 0; i < K; i++){
            cin >> asteroidX[i] >> asteroidY[i];
        }
        xPos = asteroidX[0];
        yPos = asteroidY[0];
        Q %= xLimit;
        P %= yLimit;
        int indx = -1;
        while(!hit){
            xPos = (xPos + Q) % xLimit;
            yPos = (yPos + P) % yLimit;
            for(int i = 0; i < K; i++){
                if(asteroidX[i] == xPos && asteroidY[i] == yPos){
                    indx = i;
                    hit = true;
                    goto HIT;
                }
            }
        }
        HIT:
        results.push_back(indx);
    }
    for(int i : results){
        cout << i << endl;
    }
}