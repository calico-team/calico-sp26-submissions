// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};
int main() {
    cin.tie(0)->sync_with_stdio(false);
	int t;
    cin >> t;
    while(t--){
        int gx, gy, mx, my, i;
        cin >> gx >> gy >> mx >> my;
        int time = 1;
        bool surrounded = false;
        set<pair<int, int>>myNextPoints;
        set<pair<int, int>>myCurrentPoints;
        set<pair<int, int>>grNextPoints;
        set<pair<int, int>>grCurrentPoints;
        map<pair<int, int>, bool>myCel;
        map<pair<int, int>, bool>grCel;
        grCurrentPoints.insert({gx, gy});
        myCurrentPoints.insert({mx, my});
        myCel[{mx, my}] = true;
        grCel[{gx, gy}] = true;
        for(i = 0; i < 4; ++i) myNextPoints.insert({mx+nx[i], my+ny[i]});
        for(i = 0; i < 4; ++i) grNextPoints.insert({gx+nx[i], gy+ny[i]});
        while(!surrounded){
            if(time % 2 == 0){
                set<pair<int, int>>newPoints;
                for(pair<int, int>point : grNextPoints){
                    if(myCel[point] || grCel[point]) continue;
                    grCurrentPoints.insert(point);
                    grCel[point] = true;
                    for(i = 0; i < 4; ++i){
                        pair<int, int>np = {point.first+nx[i], point.second+ny[i]};
                        if(!(grCel[np] || myCel[np])) newPoints.insert(np);
                    }
                }
                grNextPoints.clear();
                for(pair<int, int>point : newPoints) if(!(grCel[point] || myCel[point])) grNextPoints.insert(point);
            }
            if(time % 7 == 0){
                set<pair<int, int>>newPoints;
                bool any = false;
                for(pair<int, int>point : myNextPoints){
                    if(grCel[point] || myCel[point]) continue;
                    any = true;
                    myCurrentPoints.insert(point);
                    myCel[point] = true;
                    for(i = 0; i < 4; ++i){
                        pair<int, int>np = {point.first+nx[i], point.second+ny[i]};
                        if(!(grCel[np] || myCel[np])) newPoints.insert(np);
                    }
                }
                myNextPoints.clear();
                for(pair<int, int>point : newPoints) myNextPoints.insert(point);
                if(!any) break;
            }
            // cout << time << endl;
            // // cout << myCurrentPoints.size() << endl;
            // // cout << grCurrentPoints.size() << endl;
            // cout << "BREAK" << endl;
            // cout << "MY" << endl;
            // for(pair<int, int>point : myNextPoints) cout << point.first << " " << point.second << endl;
            // cout << "GR" << endl;
            // for(pair<int, int>point : grCurrentPoints) cout << point.first << " " << point.second << endl;
            // cout <<"BREAK" << endl;
            // cout << endl;
            // if(time > 21) break;
            ++time;
        }
        cout << myCurrentPoints.size() << '\n';
    }
}
