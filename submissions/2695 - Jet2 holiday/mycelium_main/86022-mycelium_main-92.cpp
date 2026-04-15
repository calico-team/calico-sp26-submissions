#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll time(ll x, ll y,ll gx,ll gy)
{
    ll d = abs(x - gx) + abs(y - gy);
    return (d / 2) * 2 + (d % 2 == 1 ? 2 : 0);
}

ll bfs(ll gx, ll gy, ll mx, ll my)
{
    queue<pair<pair<ll, ll>, ll>> q;
    set<pair<ll, ll>> st;

    q.push({{mx, my}, 0});
    st.insert({mx, my});

    ll res = 0;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        ll x = now.first.first;
        ll y = now.first.second;
        ll t = now.second;

        if (time(x,y,gx,gy) <= t)
            continue;

        res++;

        for (int i=0; i<4; i++)
        {
            ll nx = x + dir[i][0];
            ll ny = y + dir[i][1];

            if (st.find({nx, ny}) == st.end())
            {
                st.insert({nx, ny});
                q.push({{nx, ny}, t + 7});
            }
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll gx, gy, mx, my;
        cin >> gx >> gy >> mx >> my;
        cout << bfs(gx, gy, mx, my) << endl;
    }
}