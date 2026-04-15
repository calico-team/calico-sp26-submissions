#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int xg,yg,xm,ym;
        cin >> xg >> yg >> xm >> ym;
        map<pair<int,int>,int> grid;
        int i=0;
        priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>> qu;
        qu.push(make_pair(make_pair(0,-1),make_pair(xg,yg)));
        qu.push(make_pair(make_pair(0,1),make_pair(xm, ym)));
        int addm = 1;
        int totalm = 0;
        // grid[make_pair(xm,ym)] = 1;
        // grid[make_pair(xg,yg)] = -1;
        while(addm > 0 && !qu.empty()){
            pair<pair<int,int>,pair<int,int>> temp = qu.top();
            qu.pop();
            //cout << addm;
            if(temp.first.second == 1){
                if(grid.find(make_pair(temp.second.first, temp.second.second)) == grid.end())totalm++;
                addm--;
            }
            if(grid.find(make_pair(temp.second.first, temp.second.second)) != grid.end())continue;
            grid[make_pair(temp.second.first, temp.second.second)] = temp.first.first;
            if(temp.first.second == -1){
                if(grid.find(make_pair(temp.second.first+1, temp.second.second)) == grid.end()){
                    //grid[make_pair(temp.second.first+1, temp.second.second)] = -1;
                    qu.push(make_pair(make_pair(temp.first.first+2, temp.first.second), make_pair(temp.second.first+1, temp.second.second)));
                }
                if(grid.find(make_pair(temp.second.first-1, temp.second.second)) == grid.end()){
                    //grid[make_pair(temp.second.first-1, temp.second.second)] = -1;
                    qu.push(make_pair(make_pair(temp.first.first+2, temp.first.second), make_pair(temp.second.first-1, temp.second.second)));
                }
                if(grid.find(make_pair(temp.second.first, temp.second.second+1)) == grid.end()){
                    //grid[make_pair(temp.second.first, temp.second.second+1)] = -1;
                    qu.push(make_pair(make_pair(temp.first.first+2, temp.first.second), make_pair(temp.second.first, temp.second.second+1)));
                }
                if(grid.find(make_pair(temp.second.first, temp.second.second-1)) == grid.end()){
                    //grid[make_pair(temp.second.first, temp.second.second-1)] = -1;
                    qu.push(make_pair(make_pair(temp.first.first+2, temp.first.second), make_pair(temp.second.first, temp.second.second-1)));
                }
            }else{
                //addm--;
                if(grid.find(make_pair(temp.second.first+1, temp.second.second)) == grid.end()){
                    addm++;
                    //totalm++;
                    //grid[make_pair(temp.second.first+1, temp.second.second)] = 1;
                    qu.push(make_pair(make_pair(temp.first.first+4, temp.first.second), make_pair(temp.second.first+1, temp.second.second)));
                }
                if(grid.find(make_pair(temp.second.first-1, temp.second.second)) == grid.end()){
                    addm++;
                    //totalm++;
                    //grid[make_pair(temp.second.first-1, temp.second.second)] = 1;
                    qu.push(make_pair(make_pair(temp.first.first+4, temp.first.second), make_pair(temp.second.first-1, temp.second.second)));
                }
                if(grid.find(make_pair(temp.second.first, temp.second.second+1)) == grid.end()){
                    addm++;
                    //totalm++;
                    //grid[make_pair(temp.second.first, temp.second.second+1)] = 1;
                    qu.push(make_pair(make_pair(temp.first.first+4, temp.first.second), make_pair(temp.second.first, temp.second.second+1)));
                }
                if(grid.find(make_pair(temp.second.first, temp.second.second-1)) == grid.end()){
                    addm++;
                    //totalm++;
                    //grid[make_pair(temp.second.first, temp.second.second-1)] = 1;
                    qu.push(make_pair(make_pair(temp.first.first+4, temp.first.second), make_pair(temp.second.first, temp.second.second-1)));
                }
            }
        }
        cout << totalm << endl;
    }
}