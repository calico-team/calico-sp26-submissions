/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        long long N,P,R,K;
        cin>>N>>P>>R>>K;
        long long pow=P;
        bool win=true;
        for(int j=0;j<N;j++){
            long long E;
            cin>>E;
            if(win){
                pow-=E;
                if(pow<0){
                    win=false;
                }
                else if((j+1)%K==0){
                    pow+=R;
                }
            }
        }
        if(win){
            cout<<"nah i'd win"<<endl;
        }
        else{
            cout<<"nah i'd lose"<<endl;
        }
    }
    return 0;
}
void read_your_input() {
}