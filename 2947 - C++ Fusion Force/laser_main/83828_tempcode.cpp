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
        bool flag=false;
        while (!flag) {
            c++;
            //cout << "indices " << lx << " " << ly << endl;
            for (int k=0; k<ast.size(); k++) {
                if (ast[k].first==lx && ast[k].second==ly) {
                    flag=true;
                    cout << k+1;
                    //cout << endl << ast[k].first << " " << ast[k].second << endl;
                }
            }
            lx=(lx+q)%n;
            ly=(ly+p)%m;
            if (c>1000) {cout << 0; break;}
        }
        if (i!=t-1) cout << endl;
    }
}