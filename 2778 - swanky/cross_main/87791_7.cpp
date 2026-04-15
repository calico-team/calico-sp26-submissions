#include<iostream>
#include<vector>
using namespace std;

int main(){
    int test;
    cin>>test;

    vector<vector<int>> v(1000,vector<int>(1000,-1));
    
    int val=0;
    for(int i=0;i<1000;i++){
        val=(i*2)%5;
        for(int j=0;j<1000;j++)
            v[i][j]=(val+j)%5;
    }

    for(int t=0;t<test;t++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
    }
}