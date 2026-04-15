#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int solve(int X_G,int Y_G,int X_M,int Y_M){
    int ans=0;
    char w[49][49]={' '};
    w[24+X_G][24+Y_G]='G';
    w[24+X_M][24+Y_M]='M';
    for(int t=2;t<=999;t++){
        for(int i=0;i<=49;i++){
            for(int j=0;j<=49;j++){
                if(w[i][j]=='M'&&t%7==0){
                    if(w[i+1][j]==' '&&w[i+2][j]!='W'&&w[i+1][j+1]!='W'&&w[i+1][j-1]!='W'){
                        w[i+1][j]='M';
                        ans++;
                    }
                    if(w[i-1][j]==' '&&w[i-2][j]!='W'&&w[i-1][j+1]!='W'&&w[i-1][j-1]!='W'){
                        w[i-1][j]='M';
                        ans++;
                    }
                    if(w[i][j+1]==' '&&w[i][j+2]!='W'&&w[i+1][j+1]!='W'&&w[i-1][j+1]!='W'){
                        w[i][j+1]='M';
                        ans++;
                    }
                    if(w[i][j-1]==' '&&w[i][j-2]!='W'&&w[i+1][j-1]!='W'&&w[i-1][j-1]!='W'){
                        w[i][j-1]='M';
                        ans++;
                    }
                }else if(w[i][j]=='G'&&t%2==0){
                    if(w[i+1][j]==' '){
                        w[i+1][j]='G';
                    }
                    if(w[i-1][j]==' '){
                        w[i-1][j]='G';
                    }
                    if(w[i][j+1]==' '){
                        w[i][j+1]='G';
                    }
                    if(w[i][j-1]==' '){
                        w[i][j-1]='G';
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    for (int i=0;i<T;i++){
        int X_G,Y_G,X_M,Y_M;
        cin>>X_G>>Y_G>>X_M>>Y_M;
        cout<<solve(X_G,Y_G,X_M,Y_M)<<'\n';
    }
    return 0;
}