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

#ifdef DORMON
    #define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

void solve(){
    int n;
    cin >> n;
    vector<string> s1(n), s2(n);
    for (auto &e:s1) cin >> e;
    for (auto &e:s2) cin >> e;
    int mx = 0, mn = 0;
    for (int i = 0;i < n;i++){
        int c1 = 0, c2 = 0;
        for (int j = 0;j < n;j++){
            c1 += s1[i][j] == '#';
            c2 += s2[i][j] == '#';
        }
        mx += c1 * c2;
        mn += max(c1, c2);
    }
    cout << mx << ' ' << mn << '\n';
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