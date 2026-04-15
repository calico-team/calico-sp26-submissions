#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define aa(v_) v_.begin(),v_.end()
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

const int mod = 998244353; //1e9+7 ; //676767677; //998244353;
const int mxn = 5e4+7;
void sleep(){
    int n,m,k,t,x,y,z,w;
    cin >> n;
    int a[n],b[n];
    for(auto &i:a) cin >> i;
    if ((a[0]<=a[1]&&a[1]<=a[2])||(a[0]>=a[1]&&a[1]>=a[2])) return(void)(cout << a[0] << " " << a[1] << " " << a[2] << "\n");
    if (a[1]<a[0]) cout << a[0] << " " << min(a[0],a[2]) << " " << a[2] << "\n";
    else cout << a[0] << " " << max(a[0],a[2]) << " " << a[2] << "\n";    
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n=1;
    cin >> n;
    while (n--) sleep();
}