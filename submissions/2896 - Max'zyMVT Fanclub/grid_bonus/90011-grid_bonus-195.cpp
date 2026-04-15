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
    vector<int> a(n), b(n), lb(n), ub(n);
    for (auto &e:a) cin >> e;
    lb[0] = ub[0] = a[0];
    for (int i = 1;i < n;i++){
        if (a[i] < lb[i - 1]){
            lb[i] = a[i];
            ub[i] = lb[i - 1];
        }
        else if (a[i] > ub[i - 1]){
            lb[i] = ub[i - 1];
            ub[i] = a[i];
        }
        else lb[i] = ub[i] = a[i];
    }
    b[n - 1] = lb[n - 1];
    for (int i = n - 2;i >= 0;i--) b[i] = max(lb[i], min(ub[i], b[i + 1]));
    cout << b << '\n';
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