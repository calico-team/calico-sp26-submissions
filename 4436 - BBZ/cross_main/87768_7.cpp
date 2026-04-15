#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        vector<vector<int>>arr(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0 && i+1<m && j-1>=0 && j+1<n){
                    bool check[5]={0,0,0,0,0};
                    if(arr[i-1][j]!=-1){
                        check[arr[i-1][j]]=1;
                    }
                    if(arr[i+1][j]!=-1){
                        check[arr[i+1][j]]=1;
                    }
                    if(arr[i][j-1]!=-1){
                        check[arr[i][j-1]]=1;
                    }
                    if(arr[i][j+1]!=-1){
                        check[arr[i][j+1]]=1;
                    }
                    if(arr[i][j]!=-1){
                        check[arr[i][j]]=1;
                    }
                    if(arr[1][j]==-1){
                        for(int k=0;k<5;k++){
                            if(!check[k]){
                                arr[i][j]=k;
                                check[k]=1;
                                break;
                            }
                        }
                    }
                    if(arr[i-1][j]==-1){
                        for(int k=0;k<5;k++){
                            if(!check[k]){
                                arr[i-1][j]=k;
                                check[k]=1;
                                break;
                            }
                        }
                    }
                    if(arr[i+1][j]==-1){
                        for(int k=0;k<5;k++){
                            if(!check[k]){
                                arr[i+1][j]=k;
                                check[k]=1;
                                break;
                            }
                        }
                    }
                    if(arr[i][j-1]==-1){
                        for(int k=0;k<5;k++){
                            if(!check[k]){
                                arr[i][j-1]=k;
                                check[k]=1;
                                break;
                            }
                        }
                    }
                    if(arr[i][j+1]==-1){
                        for(int k=0;k<5;k++){
                            if(!check[k]){
                                arr[i][j+1]=k;
                                check[k]=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==-1){
                    cout << 0 << " ";
                }
                else{
                    cout << arr[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
}