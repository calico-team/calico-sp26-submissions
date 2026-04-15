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
    vector<string> grd1(n),grd2(n);
    vector<int> v(n);
    for(auto &i:grd1) cin >> i;
    for(auto &i:grd2) cin >> i;
    for (int i = 0; i < n; i++)
    {
        x=0;
        for (int j = 0; j < n; j++)
        {
            if (grd2[i][j]=='#') x++;
        }
        v[i]=x;
    }
    x=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grd1[i][j]=='#') x+=v[i];
        }
        
    }
    vector<string> s1,s2;
    s1=grd1;s2=grd2;
    int mn=0;
    for(int i=0;i<n;i++){
            int cnt1=0,cnt2=0;
            for(int j=0;j<n;j++){
                if(s1[i][j]=='#')cnt1++;
                if(s2[i][j]=='#')cnt2++;
            }
            mn+=max(cnt1,cnt2);
        }
    cout << x << " " << mn << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n=1;
    cin >> n;
    while (n--) sleep();
}