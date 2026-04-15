// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--){
        int k, n, m, p, q, i;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int, int>>asteroids(k);
        map<pair<int, int>, int>visited;
        for(i = 0; i < k; ++i){
            cin >> asteroids[i].first >> asteroids[i].second;
            visited[{asteroids[i].first, asteroids[i].second}] = i;
        }
        bool hit = false;
        int x = asteroids[0].first+q;
        int y = asteroids[0].second+p;
        // int sp = 0;
        while(!hit){
            // sp++;
            // if(sp > 6) break;
            x%=n;
            y%=m;
            if(visited.find({x, y}) != visited.end()){
                cout << visited[{x, y}] << '\n';
                break;
            }
            x+=q;
            y+=p;
        }
    }
}
