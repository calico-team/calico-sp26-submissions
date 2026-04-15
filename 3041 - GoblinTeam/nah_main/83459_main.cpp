/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--){
        long long N, P, R, K;
        vector<long long>E(N);
        
        for(int i = 0; i< N;i++){
            cin >> E[i];
        }
        long long c = P;
        int cnt = 0;
        bool l = false;
        for(int i = 0;i< N;i++){
            if(c < E[i]){
                l = true;
                break;
            }
            c-= E[i];
            cnt++;
            if(cnt % K == 0){
                c +=R;
            }
        }
        if(l){
            cout << "nah i'd lose" << endl;
        }
        else{
            cout << "nah i'd win" << endl;
        }
    }
    
    return 0;
}