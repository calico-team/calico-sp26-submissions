//written by sarah
#include <bits/stdc++.h>

using namespace std;

int main()
{
    //problem 4 - laser
    int t, k, n, m, p, q, lx, ly, x, y;
    vector<pair<int, int>> ast;
    cin >> t;

    for (int i=0; i<t; i++) {
        int c=0;
        cin >> k >> n >> m >> p >> q;
        cin >> lx >> ly;
        ast.clear();
        for (int j=1; j<k; j++) {
            cin >> x >> y;
            ast.push_back({x, y});
        }
        //laser sim - brute force
        x=lx;
        y=ly;
        bool flag=false;
        while (!flag) {
            if (x==lx && y==ly) {
                cout << 0;
                break;
            }
            for (int z=0; z<ast.size(); z++) {
                if (ast[z].first==lx && ast[z].second==ly) {
                    flag=true;
                    cout << z+1;
                    break;
                    //cout << endl << ast[k].first << " " << ast[k].second << endl;
                }
            }
            lx=(lx+q)%n;
            ly=(ly+p)%m;

        }
        if (i!=t-1) cout << endl;
    }
}