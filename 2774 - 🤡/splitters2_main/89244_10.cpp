#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define aa(v_) v_.begin(),v_.end()
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

const int mod = 998244353; //1e9+7 ; //676767677; //998244353;
const int mxn = 5e4+7;
const double l3 = 0.477121255 , l2 = 0.301029996 ;

vector<int> b3(int n){
    vector<int> v;
    while(n>0){
        v.push_back(n%3);
        n/=3;
    }
    return v;
}

vector<string> small(int n,int m,int k){ // n<2^m3^k
    vector<string> ans(3);
    int t=pow(3,k);
    int r=n/t,s=n%t;
    vector<bool> st(m);
    for (int i = 0; i < m; i++)
    {
        st[i]=(r>>(m-i-1))&1;
        //cout << st[i] << " ";
    }
    vector<int> st3;
    st3=b3(s);
    st3.resize(k);
    reverse(aa(st3));
    //cout << "\n";
    //for(auto i:st3) cout << i << " ";
    //cout << "\n";
    for (int i = 0; i < m; i++)
    {
        if (st[i]){
            ans[0]+=".^.";
            ans[1]+=">S>";
            ans[2]+="...";
        }else{
            ans[0]+=".X.";
            ans[1]+=">S>";
            ans[2]+="...";
        }
    }
    for (int i = 0; i < k; i++)
    {
        ans[1]+=">S>";
        if (st3[i]==0){
            ans[0]+=".X.";
            ans[2]+=".X.";
        }else if (st3[i]==1){
            ans[0]+=".^.";
            ans[2]+=".X.";
        }else{
            ans[0]+=".^.";
            ans[2]+=".v.";
        }
    }
    return ans;
}

void sleep(){
    int n,m,k,t,x,y,z,w;
    int x1,x2,y1,y2;
    cin >> n >> m >> k;
    vector<int> st(m);
    for(int i=0;((double)(m)*l2+(double)(k-i)*l3>41)&&(i<k);i++){
        x=i+1;
    }
    for(int i=0;((double)(m-i)*l2+(double)(k-x+1)*l3>41)&&(i<m);i++) y=i+1;
    vector<string> tmp(3);
    for (int i = 0; i < x; i++)
    {
        tmp[0]+=".X.";
        tmp[1]+=">S>";
        tmp[2]+=".X.";
    }
    for (int i = 0; i < y; i++)
    {
        tmp[0]+=".X.";
        tmp[1]+=">S>";
        tmp[2]+="...";
    }
    
    
    vector<string> ans;
    ans=small(n,m,k);
    cout << "3 " << ans[0].size()+tmp.size()+2 << "\n";
    cout << "v"+tmp[0]+ans[0]+"." << "\n" << ">"+tmp[1]+ans[1]+"X" << "\n" << "."+tmp[2]+ans[2]+"." << "\n";
    // 1/2 , 1/4 , ... , 1/2^m
    for (int i = x; i < m; i++)
    {
        /* code */
    }
    
}

/*
.>?
>S>
.>?

.>?
>S>
...

*/

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n=1;
    cin >> n;
    while (n--) sleep();
}