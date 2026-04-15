#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        char grid[50][50];
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++)
                grid[i][j] = '-';
        char steps[9] = {'g', 'g', 'g', 'm', 'g', 'g', 'g', 'g', 'm'};
        int gx, gy, mx, my;
        cin >> gx >> gy >> mx >> my;
        queue<pair<int, pair<int, int>>> g;
        queue<pair<int, pair<int, int>>> m;
        
        g.push({0, {26+gx, 25+gy}});
        g.push({0, {24+gx, 25+gy}});
        g.push({0, {25+gx, 26+gy}});
        g.push({0, {25+gx, 24+gy}});
        
        //cout << x << " " << y << endl;
        grid[25+mx][25+my] = 'm';
        m.push({0, {26+mx, 25+my}});
        m.push({0, {24+mx, 25+my}});
        m.push({0, {25+mx, 26+my}});
        m.push({0, {25+mx, 24+my}});
        
        int turn = 0, gturn = 0, mturn = 0;
        while (!m.empty()) {
            /*
            for (int i = 0; i < 50; i++) { 
                for (int j = 0; j < 50; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            cout << endl;//*/
            if (steps[turn] == 'g') {
                while (g.front().first == gturn) {
                    int x = g.front().second.first;
                    int y = g.front().second.second;
                    //cout << x << " " << y << endl;
                    int cur = g.front().first;
                    g.pop();
                    if (grid[x][y] == '-') {
                        grid[x][y] = 'g';
                        g.push({cur+1, {x+1, y}});
                        g.push({cur+1, {x-1, y}});
                        g.push({cur+1, {x, y+1}});
                        g.push({cur+1, {x, y-1}});
                    }
                }
                gturn++;
            }
            if (steps[turn] == 'm') {
                while (m.front().first == mturn) {
                    int x = m.front().second.first;
                    int y = m.front().second.second;
                    int cur = m.front().first;
                    m.pop();
                    if (grid[x][y] == '-') {
                        grid[x][y] = 'm';
                        m.push({cur+1, {x+1, y}});
                        m.push({cur+1, {x-1, y}});
                        m.push({cur+1, {x, y+1}});
                        m.push({cur+1, {x, y-1}});
                    }
                }
                mturn++;
            }
            turn++;
            turn %= 9;
        }
        int ans = 0;
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++)
                if (grid[i][j] == 'm') ans++;
        cout << ans;
    }
}