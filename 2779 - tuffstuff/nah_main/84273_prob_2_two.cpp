// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector <int> vec (N);
        for (int j = 0; j < N; j++){
            cin >> vec[j];
        }
        bool yes_or_no = true;
        for (int j = 0; j < N + 1; j++){
            if (P > 0){
                if (j + 1 >= K && j != 0){
                    P+=R;
                    
                }
               P = P - vec[j];

            }
            else{
                cout << "nah, i'd lose" << endl;
                yes_or_no = false;
                break;
            }
        }
        if (yes_or_no == true){
        cout << "nah, i'd win" << endl;}
        

    }

}
