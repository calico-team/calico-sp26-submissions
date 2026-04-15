#include <bits/stdc++.h>
using namespace std;
void eachCase()
{
    int n;
    cin>>n;
    vector<int> C(n+2);
    

    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }



    int cur_left=C[0],cur_right=C[0];
    for(int i=1;i<n;i++)
    {

        if(C[i]>=cur_left&&C[i]<=cur_right)
        {
            
            
            
            cur_right=C[i];
            cur_left=C[i];
            
            cout<<C[i]<<" ";

            
        }

        else if(C[i]>cur_right)
        {
            cout<<cur_right<<" ";
            cur_left=cur_right;
            cur_right=C[i];
            
            
        }
        else if(C[i]<cur_left)
        {
            cout<<cur_left<<" ";
            cur_right=cur_left;
            cur_left=C[i];
            
            
        }
        else{
            cout<<"ZMMP";
        }






    }


    cout<<cur_left<<endl;
}


int main()
{
    int T;
    cin>>T;
    while(T--) eachCase();
}