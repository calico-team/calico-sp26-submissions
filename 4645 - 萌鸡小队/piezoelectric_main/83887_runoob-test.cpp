#include <iostream> 
using namespace std; 
 int main() 
{ 
    int l,w,e,r;
    cin>>l>>w>>e>>r;
    int p=(l+w)*2;
    int a=p*r;
    int h=e/a;
    cout<<h;
   return 0; 
}