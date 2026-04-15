#include<iostream>
#include<vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        bool s1[N][N];
        bool s2[N][N];
        int presum_r[N];
      
        memset(presum_r,0,N*sizeof(int));
       
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                char a;
                cin>>a;
                if(a=='#') s1[i][j]=true;
                else s1[i][j]=false;

                presum_r[i]+=s1[i][j];


            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                char a;
                cin>>a;
                if(a=='#') s2[i][j]=true;
                else s2[i][j]=false;

                
            }
        }

        int max_val=0;
        int min_val=0;

        

        for(int i=0;i<N;i++){
            int s1_sum=0,s2_sum=0;
            for(int j=0;j<N;j++){
                if(s2[i][j]){
                    // cout<<i<<" "<<presum_r[i]<<endl;
                    max_val+=presum_r[i];
                }

                s1_sum+=s1[i][j];
                s2_sum+=s2[i][j];
                

            }

            min_val+=max(s1_sum,s2_sum);
            
        }

        cout<<max_val<<" "<<min_val<<endl;


    }
}