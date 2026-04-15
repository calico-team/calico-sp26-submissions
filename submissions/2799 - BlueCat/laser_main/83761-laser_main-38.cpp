#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int k,n,m,p,q;
        cin>>k>>n>>m>>p>>q;

        vector<pair<int,int>> a(k);
        map<pair<int,int>,int> mp;

        for(int i=0;i<k;i++){
            cin>>a[i].first>>a[i].second;
            mp[a[i]]=i;
        }

        int x=a[0].first,y=a[0].second;

        int cx=x,cy=y;

        while(true){
            cx=(cx+q)%n;
            cy=(cy+p)%m;

            if(mp.count({cx,cy})){
                cout<<mp[{cx,cy}]<<"\n";
                break;
            }

            if(cx==x&&cy==y){
                cout<<0<<"\n";
                break;
            }
        }
    }

    return 0;
}