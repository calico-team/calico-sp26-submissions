// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int k,n,m,p,q;
        cin>>k>>n>>m>>p>>q;
        vector<pair<int,int>> v(k);
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            v[i]=make_pair(a,b);
        }
        int currX=get<0>(v[0]);
        int currY=get<1>(v[0]);
        bool found=false;
        int idx=-1;
        bool first=true;
        int startX=currX;
        int startY=currY;//curry
        while(true){
            currX+=q;
            currY+=p;
            if(currX>=n){
                currX%=n;
            }
            if(currY>=m){
                currY%=m;
            }
            if(currX==startX&&startY==currY&&!first){
                idx=0;
            }
            first=false;
            for(int i=0;i<k;i++){
                if(currX==v[i].first&&currY==v[i].second){
                    idx=i;
                }
            }
            if(idx!=-1){
                break;
            }
        }
        cout<<idx<<endl;
    }
}
