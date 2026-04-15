#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        int k,n,m,p,q;
        cin>>k>>n>>m>>q>>p;
        set<vector<int>> s;
        vector<vector<int>> v(k,vector<int>(2));
        for(int i=0;i<k;i++){
            cin>>v[i][0]>>v[i][1];
            s.insert(v[i]);
        }
        int x=v[0][0],y=v[0][1];
        while(true){
            x+=p;
            y+=q;
            x%=n;
            y%=m;
            if(s.find({x,y})!=s.end()){
                break;
            }
        }
        for(int i=0;i<k;i++){
            if(v[i][0]==x && v[i][1]==y){
                cout<<i<<endl;
                break;
            }
        }
    }
}


