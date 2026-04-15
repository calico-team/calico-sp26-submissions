// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
    while(T--)
    {
        int N, M; cin >> N >> M;
        vector<vector<int>> seating(N, vector<int>(M, 0));
        int reference = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                seating[i][j] = (reference + j)%5;
            }
            reference += 2;
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cout << seating[i][j] << " ";
            }
            cout << endl;
        }
    }
}
