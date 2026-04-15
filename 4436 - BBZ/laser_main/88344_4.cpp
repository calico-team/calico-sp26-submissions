#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k,m,n,p,q;
        cin >> k >> n >> m >> p >> q;
        vector<vector<int>>arr(m,vector<int>(n,0));
        map<pair<int,int>,int>mp;
        int si,sj;
        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            if(i==0){
                si=y,sj=x;
            }
            arr[y][x]=1;
            mp[{y,x}]=i;
        }
        int i=si,j=sj;
        while(1){
            i=(i+p)%m;
            j=(j+q)%n;
            if(arr[i][j]==1){
                cout << mp[{i,j}] << endl;
                break;
            }
        }
    }
}