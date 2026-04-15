/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--){
        string A, B;
        cin >> A >> B;
        int j = 0;
        for(int i = 0; i< A.size();i++){
            if(j < B.size() && A[i] == B[j]){
                j++;
            }
            else{
                A[i] = '#';
            }
        }
        cout << A <<endl;
    }
    
    return 0;
}