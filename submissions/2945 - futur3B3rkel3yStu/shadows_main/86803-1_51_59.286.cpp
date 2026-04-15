/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if(!(cin>>T)){
        return 0;
    }
    while(T--){
        int N;
        cin>>N;
        vector<int> cnt1(N,0);
        for(int i=0;i<N;i++){
            string row;
            cin>>row;
            for(char c: row){
                if(c=='#') cnt1[i]++;
            }
        }
        vector<int> cnt2(N,0);
        for(int j=0;j<N;j++){
            string row;
            cin>>row;
            for(char c: row){
                if(c=='#') cnt2[j]++;
            }
        }
        long long maxv=0;
        long long min=0;
        for(int k=0;k<N;k++){
            maxv+=(long long)cnt1[k]*cnt2[k];
            min+=max(cnt1[k],cnt2[k]);
        }
        cout<<maxv<<" "<<min<<endl;
        
    }
    
    return 0;
}