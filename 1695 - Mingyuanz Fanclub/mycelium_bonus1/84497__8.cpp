#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#include <array>
#include <iomanip> // cout << fixed << setprecision(n);
#include <cmath>
#include <map>

using namespace std;
const bool TEST_CASE = true;

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* name, T value) {
    std::cout << name << " : " << value << '\n';
}

template<typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* names, T value, Args... args){
    const char* comma = strchr(names, ',');
    std::cout.write(names, comma - names) << " : " << value << " | ";
    Debug(comma + 1, args...);
}
template<typename T> 
ostream& operator<<(ostream& out, vector<T> &a){
    for (auto &x : a) out << x << ' '; 
    return out;
};

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

#ifdef DORMON
    #define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

const int SHIFT = 3000;

struct A {
    int i, j;
};

void solve(){
    vector<vector<int>> vis(2 * SHIFT, vector<int>(2 * SHIFT, 0));
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    queue<A> g, m, ng, nm;
    int ans = 1, trick = 0;
    g.push({a, b});
    m.push({c, d});
    auto get = [&](int i, int j) -> int {
        return vis[i + SHIFT][j + SHIFT];
    };
    auto update = [&](int i, int j, int val) -> void {
        vis[i + SHIFT][j + SHIFT] = val;
    };
    update(a, b, 1);
    update(c, d, 2);
    while (!m.empty()){
        debug(trick);
        trick++;
        if (trick % 2 == 0){
            while (!g.empty()){
                auto [i, j] = g.front(); g.pop();
                for (auto [di, dj]:dir){
                    if (get(i + di, j + dj) == 0){
                        ng.push({i + di, j + dj});
                        update(i + di, j + dj, 1);
                    } 
                }
            }
            swap(g, ng);
        }
        if (trick % 7 == 0){
            while (!m.empty()){
                auto [i, j] = m.front(); m.pop();
                for (auto [di, dj]:dir){
                    if (get(i + di, j + dj) == 0){
                        nm.push({i + di, j + dj});
                        update(i + di, j + dj, 2);
                        ans++;
                    }
                }
            }
            swap(m, nm);
        }
    }
    cout << ans << '\n';
}


int main()
{
    #ifndef DORMON
        ios_base::sync_with_stdio(false); 
    #endif
    cin.tie(0);
    int q = 1; 
    if (TEST_CASE) cin >> q;
    while (q--){
        solve();
    }
}