#include<bits/stdc++.h>
using namespace std;

int a[105];
int b[105];
int dp[105][105];
int prv[105][105];
int use[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        string aa,bb;cin>>aa>>bb;
        int cur=0;
        string ans;
        for(int i=0;i<aa.size();i++){
            if(cur<bb.size()&&aa[i]==bb[cur]){
                cur++;
                ans.push_back(aa[i]);
            }else{
                ans.push_back('#');
            }
        }
        cout<<ans<<"\n";
        /*
        for(int i=0;i<=aa.size()+1;i++)for(int j=0;j<=bb.size()+1;j++)dp[i][j]=0;
        dp[0][0]=1;
        for(int i=1;i<=aa.size();i++)for(int j=1;j<=bb.size();j++){
            dp[i][j]=dp[i-1][j-1]&(a[i]==b[i]);
            use[]
        }
        */
    }
}