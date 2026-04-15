#include <bits/stdc++.h>
#define DEBUG false
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

signed main() {
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    int t;
    cin>>t;
    while(t--){
        int N, P, R, K;
        cin>>N>>P>>R>>K;
        vector<int> curses;
        curses.assign(N, 0);
        int curse=0;
        int rct = 0;
        bool failed = false;
        for(int i = 0; i < N; i++){
            cin>>curses[i];
        }
        for(int i = 0; i < N; i++){
            if(P>=curses[curse]){
                P-=curses[curse];
                curse++;
                rct++;
            }else if(rct>=K){
                P+=R;
                rct=0;
            }else{
                failed=true;
                cout<<"nah i'd lose"<<endl;
                break;
            }
        }
        if(!failed){
            cout<<"nah i'd win"<<endl;
        }
    }
}