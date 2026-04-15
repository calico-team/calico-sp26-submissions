#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int,int>>;
using vvi = vector<vector<int>>;
using pi = pair<int,int>;
int stringify(int x, int y){
    return 10000*x+y;
}
int stringiby(pi a){
    return 10000*a.first+a.second;
}
pi add(pi a,pi b){
    return {a.first+b.first,a.second+b.second};
}
void solve() {
    int XG,YG,XM,YM;cin>>XG>>YG>>XM>>YM;
    vpi newMic = {{XM,YM}};
    set<int> visted;
    vpi newGra = {{XG,YG}};
    vpi moves = {{0,1},{0,-1},{1,0},{-1,0}};
    int time = 0;
    visted.insert(stringify(XG,YG));
    visted.insert(stringify(XM,YM));
    int total = 1;
    while (newMic.size()>0){
        time++;
        if (time%2==0){
            vpi oldGra = newGra;
            newGra = {};
            for (pi newG:oldGra){
                for (pi move:moves){
                    pi newSpot = add(newG,move);
                    int code = stringiby(newSpot);
                    if (visted.count(code))continue;
                    visted.insert(code);
                    newGra.push_back(newSpot);
                }
            }
        }
        if (time%7==0){
            vpi oldMic = newMic;
            newMic = {};
            for (pi newM:oldMic){
                for (pi move:moves){
                    pi newSpot = add(newM,move);
                    int code = stringiby(newSpot);
                    if (visted.count(code))continue;
                    visted.insert(code);
                    newMic.push_back(newSpot);
                    total++;
                }
            }
        }
    }
    cout<<total<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;cin>>T;
    while (T--)solve();
    return 0;
}