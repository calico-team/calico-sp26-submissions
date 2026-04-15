#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> a;
    long long v;

    while(cin >> v) a.push_back(v);
    if(a.empty()) return 0;
    int t = a[0];
    int p = 1;

    for(int _=0; _<t; _++){
        long long gx = a[p++];
        long long gy = a[p++];
        long long mx = a[p++];
        long long my = a[p++];

        map<pair<long long,long long>,int> vis;

        vis[{gx,gy}] = 0;
        vis[{mx,my}] = 1;

        deque<pair<long long,long long>> g, m;

        g.push_back({gx,gy});
        m.push_back({mx,my});

        long long mc = 1;
        long long tck = 0;
        // geh
        while(!m.empty()){
            tck++;

            if(tck % 2 == 0){
                int sz = g.size();

                for(int i=0;i<sz;i++){
                    auto c = g.front();
                    g.pop_front();

                    long long x = c.first;
                    long long y = c.second;

                    vector<pair<int,int>> d = {
                        {0,1},{0,-1},{1,0},{-1,0}
                    };

                    for(auto &z : d){
                        long long nx = x + z.first;
                        long long ny = y + z.second;

                        if(!vis.count({nx,ny})){
                            vis[{nx,ny}] = 0;
                            g.push_back({nx,ny});
                        }
                    }
                }
            }
            if(tck % 7 == 0){
                int sz = m.size();
                for(int i=0;i<sz;i++){
                    auto c = m.front();
                    m.pop_front();

                    long long x = c.first;
                    long long y = c.second;
                    vector<pair<int,int>> d = {
                        {0,1},{0,-1},{1,0},{-1,0}
                    };
                    for(auto &z : d){
                        long long nx = x + z.first;
                        long long ny = y + z.second;

                        if(!vis.count({nx,ny})){
                            vis[{nx,ny}] = 1;
                            mc++;
                            m.push_back({nx,ny});
                        }
                    }
                }
            }
            // halp
        }

        cout << mc << "\n";
    }

    return 0;
}