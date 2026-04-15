#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int xg, yg, xm, ym;
vector<pair<int,int> > qg, qm;
set<pair<int,int> > vis;

void run_step(vector<pair<int,int> >& q) {
    vector<pair<int,int> > nextq;
    for (auto tmp: q) {
        for (int d = 0 ; d < 4 ; ++d) {
            int tx = tmp.first + dir[d][0];
            int ty = tmp.second + dir[d][1];
            if (vis.count(make_pair(tx, ty))) continue;
            vis.insert(make_pair(tx, ty));
            nextq.push_back(make_pair(tx, ty));
        }
    }
    q = nextq;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d",&xg,&yg,&xm,&ym);
        qg.clear(); qm.clear(); vis.clear();
        vis.insert(make_pair(xg, yg));
        vis.insert(make_pair(xm, ym));
        qg.push_back(make_pair(xg, yg));
        qm.push_back(make_pair(xm, ym));
        int ans = 1;
        for (int tick = 1 ; ; ++tick) {
            if (tick % 2 == 0) {
                run_step(qg);
            }
            if (tick % 7 == 0) {
                run_step(qm);
                ans += qm.size();
            }
            if (qm.empty()) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}