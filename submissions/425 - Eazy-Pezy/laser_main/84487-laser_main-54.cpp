#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pll pair<long long,long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define revrep(i,a,b) for(int i=a;i>=b;i--)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl "\n"

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int f(int a,int b,int mod){
    int g = gcd(a,mod);
    if(b%g) return -1;
    a/=g; b/=g; mod/=g;
    int x=1,y=0,A=a,M=mod;
    while(M){
        int q=A/M;
        int t=A-q*M; A=M; M=t;
        t=x-q*y; x=y; y=t;
    }
    x=(x%mod+mod)%mod;
    return (x*b)%mod;
}

void solve(){
    int k,n,m,p,q;
    cin>>k>>n>>m>>p>>q;
    vpii a(k);
    rep(i,0,k) cin>>a[i].ff>>a[i].ss;
    int x0=a[0].ff, y0=a[0].ss;
    int ans=-0,best=LLONG_MAX;

    rep(i,0,k){
        int dx=(a[i].ff-x0+n)%n;
        int dy=(a[i].ss-y0+m)%m;

        int t1=f(q,dx,n);
        if(t1==-1) continue;

        int t2=f(p,dy,m);
        if(t2==-1) continue;

        int g1=gcd(q,n), g2=gcd(p,m);
        int m1=n/g1, m2=m/g2;

        int rhs=(t2 - t1%m2 + m2)%m2;
        int kk=f(m1%m2, rhs, m2);
        if(kk==-1) continue;

        int t=t1 + m1*kk;

        if(t==0) continue;

        if(t<best){
            best=t;
            ans=i;
        }
    }

    cout<<ans<<nl;
}

void test(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

int32_t main(){
    fast
    test();
    //solve();
    return 0;
}

/*
 ██████████   █████                                              
░░███░░░░███ ░░███                                               
 ░███   ░░███ ░███████    ██████   ████████  █████ ████ ████████ 
 ░███    ░███ ░███░░███  ░░░░░███ ░░███░░███░░███ ░███ ░░███░░███
 ░███    ░███ ░███ ░███   ███████  ░███ ░░░  ░███ ░███  ░███ ░███
 ░███    ███  ░███ ░███  ███░░███  ░███      ░███ ░███  ░███ ░███
 ██████████   ████ █████░░████████ █████     ░░████████ ████ █████
░░░░░░░░░░   ░░░░ ░░░░░  ░░░░░░░░ ░░░░░       ░░░░░░░░ ░░░░ ░░░░░

 Author: Dharun
*/