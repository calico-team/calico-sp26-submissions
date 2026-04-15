#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        
        int l=0; //length
        int w=0; //width
        int e=0; //electricity needed (quota)
        int r=0; //per step electricity
        
        cin>>l>>w>>e>>r;
        
        int p=0; //perimeter of car
    
        p=l+l+w+w;
        
        int power = p*r;
        
        cout<<e/power<<endl;
    }
    
    
    
	return 0;
}