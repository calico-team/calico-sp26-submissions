#include <stdio.h>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

vector<pair<int, int> > a[2][2];
set<pair<int, int> > done;
int res, old[2], now[2];

void init(){
    int x, y, x1, y1, i, j;
    scanf("%d%d%d%d", &x, &y, &x1, &y1);
    done.clear();
    now[0] = now[1] = 0;
    a[0][now[0]].clear(); 
    a[0][now[0]].push_back({x, y});
    done.insert({x, y});
    a[1][now[1]].clear();
    a[1][now[1]].push_back({x1, y1});
    done.insert({x1, y1});
}

void work(){
    int i, j, d, x, y, nx, ny, t, w;
    res = 1;
    for (t = 1; ; ++t){
        for (w = 2, i = 0; w <= 7; w += 5, ++i)
            if (t % w == 0){
                old[i] = now[i]; now[i] = 1 - now[i];
                a[i][now[i]].clear();
                for (auto p : a[i][old[i]]){
                    x = p.first; y = p.second;
                    for (d = 0; d < 4; ++d){
                        nx = x + dx[d]; ny = y + dy[d];
                        if (!done.count({nx, ny})){
                            done.insert({nx, ny});
                            a[i][now[i]].push_back({nx, ny});
                            if (w == 7) ++res;
                        }
                    }
                }

                if (w == 7 && a[i][now[i]].size() == 0){
                    printf("%d\n", res);
                    return;
                }
            }
    }
}

int main() {
    long long t, T;
    // freopen("h.in", "r", stdin);
    scanf("%lld", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}