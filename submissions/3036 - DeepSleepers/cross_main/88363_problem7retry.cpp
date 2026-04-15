// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        vector<vector<bool>> blocked(n,vector<bool>(m));
 
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                vector<int> nums = {0,1,2,3,4};
                int idx=0;           
                for(int cx=i;cx<3+i;cx++){
                    for(int cy=j;cy<3+j;cy++){
                        int x= cx-i;
                        int y=cy-j;
                        if((x==0&&y==1)||(x==1&&y==1)||(x==1&&y==0)||(x==2&&y==1)||(x==1&&y==2)){
                            if(blocked[cx][cy]){
                                nums.erase(remove(nums.begin(),nums.end(),grid[cx][cy]),nums.end());
                                //idx++;
                            }
                            else{
                                grid[cx][cy]=nums[idx];
                                idx++;
                            }
                        }

                        if((cx-i==0&&cy-j==0)||(cx-i==2&&cy-j==2)||(cx-i==2&&cy-j==0)||(cx-i==0&&cy-j==2)){

                        }
                        else{
                            blocked[cx][cy]=true;
                            //grid[cx][cy]=1;
                        }
                    }
                }
            }
        }
        vector<vector<bool>>reBlocked(n,vector<bool>(m,false));


        
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(blocked[i][j])
                {
                    if(idx>4){
                        idx=0;
                    }
                    grid[i][j]=nums[idx];
                    idx++;
                    reBlocked[i][j]=true;
                }
            }
        }
        */
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
