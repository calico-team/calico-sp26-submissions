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
        while(!found){
            currX+=q;
            currY+=p;
            if(currX>n){
                currX%=n;
            }
            if(currY>m){
                currY%=m;
            }
            pair<int,int> coord=make_pair(currX,currY);
            for(int i=0;i<k;i++){
                if(coord==v[i]){
                    idx=i;
                    found=true;
                }
            }
        }
        cout<<idx<<endl;
    }
}
