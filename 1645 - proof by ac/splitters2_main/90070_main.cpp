#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl '\n'
#define pb push_back(x)

vector<vector<char>> v(400,vector<char>(5,'.'));
int pos = 1;
void three(int tp){
    v[pos][1] = 'S';
    v[pos+1][1] = 'v';
    if(tp==0){
        v[pos][0] = 'X';
        v[pos][2] = 'X';
    }else if(tp==1){
        v[pos][0] = 'X';
        v[pos][2] = '>';
    }else if(tp==2){
        v[pos][0] = '<';
        v[pos][2] = '>';
    }
    pos+=2;
}
void two(int tp){
    v[pos][1] = 'S';
    v[pos+1][1] = 'v';
    if(tp==0){
        v[pos][0] = 'X';
    }else if(tp==1){
        v[pos][2] = '>';
    }
    pos+=2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        pos = 1;
        v=vector<vector<char>>(600,vector<char>(3,'.'));
        ll p,a,b; cin>>p>>a>>b;
        v[0][0] = '>';
        v[0][1] = 'v';
        vector<pair<int,pair<int,int>>> ab;

        //p stuff
        while(p>0){
            p--;
            ab.push_back({1,{a,b}});
            while(a&&p%2==0){
                a--;
                p/=2;
            }
            while(b&&p%3==0){
                b--;
                p/=3;
            }
            if(a==0&&p==2){
                ab.push_back({2,{a,b}});
                break;
            }
        }
        int ca = 0;
        int cb = 0;
        
        for(int i = ab.size()-1; i>=0; i--){
            int aa = ab[i].second.first;
            int bb = ab[i].second.second;
            //cout<<aa<<" "<<bb<<nl;
            if(ab[i].first==2){
                while(ca<aa){
                    two(0);
                    ca++;
                }
                while(cb<bb-1){
                    three(0);
                    cb++;
                }
                three(2);
                cb++;
            }else{
                if(cb!=bb){
                    while(ca<aa){
                        two(0);
                        ca++;
                    }
                    while(cb<bb-1){
                        three(0);
                        cb++;
                    }
                    three(1);
                    cb++;
                }else{
                    while(ca<aa-1){
                        two(0);
                        ca++;
                    }
                    two(1);
                    ca++;
                }
            }
        }
        while(pos < 600){
            v[pos][1]='v';
            pos++;
        }
        /*
        for(auto i: ab){
            cout<<"A: "<<i.second.first<<" B: "<<i.second.second<<nl;
        }
        */
        cout<<"600 3"<<nl;
        for(auto i: v){
            for(auto j: i){
                cout<<j;
            }
            cout<<nl;
        }
        
    }



    return 0;
}