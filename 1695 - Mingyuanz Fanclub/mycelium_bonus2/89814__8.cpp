#pragma GCC optimize("Ofast,unroll-loops,inline,fast-math,omit-frame-pointer")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt,tune=native,fma")
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

// #define DORMON
#ifdef DORMON
    #define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif


struct A {
    int i, j;
};

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dist = abs(a - c) + abs(b - d), L = (3 * dist) / 7 + 100;
    int ni = min(a, c) - L, xi = max(a, c) + L, nj = min(b, d) - L, xj = max(b, d) + L;
    int N = xi - ni + 1, M = xj - nj + 1;
    vector<A> g, m, ng, nm;
    vector<uint8_t> vis(N * M + 1, 0);
    int ans = 1, trick = 0;
    g.push_back({a - ni, b - nj});
    m.push_back({c - ni, d - nj});
    auto get = [&](int i, int j) -> int {
        if (i < 0 || i >= N || j < 0 || j >= M) return -1;
        return vis[j * N + i];
    };
    auto update = [&](int i, int j, int val) -> void {
        if (i >= 0 && i < N && j >= 0 && j < M) vis[j * N + i] = val;
    };
    update(a - ni, b - nj, 1);
    update(c - ni, d - nj, 2);
    while (!m.empty()){
        debug(trick);
        trick++;
        if (trick % 2 == 0){
            ng.clear();
            for (auto &[i, j]:g){
                debug(i, j);
                for (auto &[di, dj]:dir){
                    if (get(i + di, j + dj) == 0){
                        ng.push_back({i + di, j + dj});
                        update(i + di, j + dj, 1);
                    }
                }
            }
            swap(g, ng);
        }
        if (trick % 7 == 0){
            nm.clear();
            for (auto &[i, j]:m){
                for (auto &[di, dj]:dir){
                    if (get(i + di, j + dj) == 0){
                        nm.push_back({i + di, j + dj});
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