#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get_time_G(ll x, ll y, ll dx, ll dy){
    ll time_G = 2 * (abs(x - dx) + abs(y - dy)); 
    
    if (abs(dy) >= abs(dx) && y * dy < 0){
        ll Rx = max(0LL, (2 * (abs(dy) - abs(dx)) + 4) / 5);
        ll path1 = abs(dx - Rx) + abs(dy) + abs(x - Rx) + abs(y);
        ll path2 = abs(dx - (-Rx)) + abs(dy) + abs(x - (-Rx)) + abs(y);
        time_G = 2 * min(path1, path2);
    }
    
    if (abs(dx) >= abs(dy) && x * dx < 0){
        ll Ry = max(0LL, (2 * (abs(dx) - abs(dy)) + 4) / 5);
        ll path1 = abs(dx) + abs(dy - Ry) + abs(x) + abs(y - Ry);
        ll path2 = abs(dx) + abs(dy - (-Ry)) + abs(x) + abs(y - (-Ry));
        time_G = max(time_G, 2 * min(path1, path2)); 
    }
    
    return time_G;
}

void solve(){
    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    ll dx = xg - xm;
    ll dy = yg - ym;

    ll D = abs(dx) + abs(dy);
    ll max_r = (2 * D) / 5 + 2; 

    ll mycelium_t = 0;

    for (ll y = -max_r; y <= max_r; y++){
        ll low = 0, high = max_r, right_x = -1;
        while (low <= high){
            ll mid = low + (high - low) / 2;
            ll t_M = 7 * (abs(mid) + abs(y));
            ll t_G = get_time_G(mid, y, dx, dy);
            if (t_M < t_G){
                right_x = mid;
                low = mid + 1; 
            } else{
                high = mid - 1; 
            }
        }
        
        low = -max_r; high = 0; ll left_x = 1;
        while (low <= high){
            ll mid = low + (high - low) / 2;
            ll t_M = 7 * (abs(mid) + abs(y));
            ll t_G = get_time_G(mid, y, dx, dy);
            if (t_M < t_G){
                left_x = mid;
                high = mid - 1; 
            } else{
                low = mid + 1; 
            }
        }
        
        if (left_x <= right_x){
            mycelium_t += (right_x - left_x + 1);
        }
    }

    cout << mycelium_t << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}