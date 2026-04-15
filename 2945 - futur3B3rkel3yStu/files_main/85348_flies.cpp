/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    if(!(cin>>T)){
        return 0;
    }
    for(int i=0;i<T;i++){
        string A,B;
        cin>>A>>B;
        int pointer=0;
        for(int j=0;j<A.length();j++){
            if(pointer<B.length()&&A[j]==B[pointer]){
                pointer++;
            }
            else{
                A[j]='#';
            }
        }
        cout<<A<<endl;
    }
    return 0;
}