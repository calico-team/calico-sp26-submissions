// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, L, W, E, R; 
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> L >> W >> E >> R;
        int perimeter = (L*2)+(W*2);
        int each_lap = perimeter*R;
        cout << E/each_lap << endl;
    }

}
