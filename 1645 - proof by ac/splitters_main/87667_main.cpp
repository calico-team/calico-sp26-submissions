#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'
#define check(x) (x!='.'&&x!='X')


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<string> v;
        
        for(int i = 0; i < n; i++){
            string s; cin>>s;
            v.push_back(s);
        }

        queue<tuple<int,int,ll>> q;
        q.push({0,0,1});
        vector<ll> ret;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = get<0>(cur);
            int c = get<1>(cur);
            ll num = get<2>(cur);
            //cout<<r<<" "<<c<<" "<<num<<" "<< nl;
            if(r<0||c<0||r>=n||c>=m){
                ret.push_back(num);
            }else if(v[r][c]=='v') q.push({r+1,c,num});
            else if(v[r][c]=='>') q.push({r,c+1,num});
            else if(v[r][c]=='^') q.push({r-1,c,num});
            else if(v[r][c]=='<') q.push({r,c-1,num});
            
            else if(v[r][c]=='S'){
                bool down = check(v[r+1][c])&&v[r+1][c]!='^';
                bool left = check(v[r][c-1])&&v[r][c-1]!='>';
                bool right = check(v[r][c+1])&&v[r][c+1]!='<';
                bool up = check(v[r-1][c])&&v[r-1][c]!='v';
                ll count = 0;
                if(down || v[r+1][c]=='X') count++;
                if(up || v[r-1][c]=='X') count++;
                if(left || v[r][c-1]=='X') count++;
                if(right || v[r][c+1]=='X') count++;
                //cout<<count<<" c"<<nl;
                
                if(count==0) continue;
                if(down) q.push({r+1,c,num*count});
                if(right) q.push({r,c+1,num*count});
                if(up) q.push({r-1,c,num*count});
                if(left) q.push({r,c-1,num*count});
                
            }
                
        }
        if(ret.empty()) cout<<"0 1"<<nl;
        else{
            ll cur = 1;
            for(auto i: ret) cur = lcm(cur,i);
            ll sum = 0;
            for(auto i: ret) sum += cur/i;
            ll g = __gcd(cur,sum);
            sum/=g;
            cur/=g;
            cout<<sum<<" "<<cur<<nl;
        }



    }

    return 0;
}