#include<bits/stdc++.h>
#define int ll
using namespace std;

#define all(a) (a).begin(),(a).end()
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define LB lower_bound

using ll=long long;
using ull=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using ld=long double;
using vi=vector<int>;
using pii=pair<int,int>;
using vpi=vector<pii>;

template<typename _T1,typename _T2>
inline bool chkmin(_T1&x,const _T2&y){if(y<x)return x=y,1;else return 0;}
template<typename _T1,typename _T2>
inline bool chkmax(_T1&x,const _T2&y){if(y>x)return x=y,1;else return 0;}

int A,B,P;
char a[2020][4];
int b[200];

void solve(){
    cin>>P>>A>>B;
    int m=1;
    for(int i=1;i<=A;i++){
        b[A+B-i+1]=P%2;
        P/=2;
    }
    for(int i=1;i<=B;i++){
        b[B-i+1]=P%3;
        P/=3;
    }
    for(int i=1;i<=500;i++)a[i][1]=a[i][2]=a[i][3]='.';
    a[1][1]='v',a[1][2]='>',a[1][3]='.';
    for(int i=1;i<=B;i++){
        m+=2;
        a[m-1][2]='S';
        a[m-1][1]=b[i]>=1?'^':'X';
        a[m-1][3]=b[i]>=2?'v':'X';
        a[m][2]='>';
    }
    for(int i=B+1;i<=A+B;i++){
        m+=2;
        a[m-1][2]='S';
        a[m-1][1]=b[i]>=1?'^':'X';
        a[m][2]='>';
    }
    a[m][2]='X';
    cout<<"3 "<<m<<'\n';
    for(int i=1;i<=3;i++){
        for(int j=1;j<=m;j++)cout<<a[j][i];cout<<'\n';
    }
}

signed main(){
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}