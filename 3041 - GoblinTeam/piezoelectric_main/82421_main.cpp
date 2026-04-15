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
    cin >> T;
    while (T--){
        int L,W,E,R;
        cin >> L >> W >> E >> R;
        int r = 2*(L + W);
        int m = r*R;
        
        int c = 0;
        int l = 0;
        while (c < E){
            c += m;
            l++;
        }
        cout << l << endl;
    }

    return 0;
}