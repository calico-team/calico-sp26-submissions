// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    while(t--){
        long long k, n, m, p, q, i;
        cin >> k >> n >> m >> p >> q;
        vector<pair<long long, long long>>asteroids(k);
        map<pair<long long, long long>, long long>visited;
        long long second = 1e9;
        for(i = 0; i < k; ++i){
            cin >> asteroids[i].first >> asteroids[i].second;
            long long revTMin = min(asteroids[i].first/q, asteroids[i].second/p);
            long long sx = asteroids[i].first-revTMin*q;
            long long sy = asteroids[i].second-revTMin*p;
            if(visited.find({sx, sy}) != visited.end()){
                if(asteroids[visited[{sx, sy}]].first > asteroids[i].first){
                    visited[{sx, sy}] = i;
                }else if(visited[{sx, sy}] == 0){
                    second = min(second, i);
                }
            }
            else visited[{sx, sy}] = i;
        }
        bool hit = false;
        long long x = asteroids[0].first;
        long long y = asteroids[0].second;
        // long long sp = 0;
        bool firstTime = true;
        i = 1;
        while(++i){
            // if(i > 1000) break;
            //first-> check if x, y is on the row of an asteroid
            // cout << x << " " << y << endl;
            if(visited.find({x, y}) != visited.end()){
                if(visited[{x, y}] == 0){
                    if(firstTime && second != 1e9){
                        cout << second << endl;
                        break;
                    }else if(!firstTime){
                        cout << 0 << endl;
                        break;
                    }
                }else{
                    cout << visited[{x, y}] << '\n';
                    break;
                }
            }
            long long numStepsLeft = min((n-x+q-1)/q, (m-y+p-1)/p);
            x = (x+q*numStepsLeft)%n;
            y = (y+p*numStepsLeft)%m;
            firstTime = false;
        }
    }
}
