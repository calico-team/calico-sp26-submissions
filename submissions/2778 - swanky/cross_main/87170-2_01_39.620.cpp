#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> cross{{0,-1},{-1,0},{0,0},{1,0},{0,1}};

int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(m,-1));
        int x=1,y=1;
        for(int i=0;i<5;i++)
            v[x+cross[i][0]][y+cross[i][1]]=i;
        vector<bool> has(5,false);
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                has=vector<bool>(5,false);
                for(int k=0;k<5;k++){
                    if(v[i+cross[k][0]][j+cross[k][1]]!=-1)
                        has[v[i+cross[k][0]][j+cross[k][1]]]=true;
                }
                for(int k=0;k<5;k++){
                    if(v[i+cross[k][0]][j+cross[k][1]]==-1){
                        for(int l=0;l<5;l++){
                            if(!has[l]){
                                has[l]=true;
                                v[i+cross[k][0]][j+cross[k][1]]=l;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==-1)
                    v[i][j]=0;
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}