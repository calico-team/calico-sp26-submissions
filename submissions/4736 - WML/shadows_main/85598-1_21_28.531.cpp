#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<string> zgrid(N), xgrid(N);
        for(int i=0;i<N;i++)cin>>zgrid[i];
        for(int i=0;i<N;i++)cin>>xgrid[i];
        long long maxx=0, minn=0;
        for(int i=0;i<N;i++)
        {
            long long cntz=0, cntx=0;
            for(char c:zgrid[i])if(c=='#')cntz++;
            for(char c:xgrid[i])if(c=='#')cntx++;
            maxx+=cntz*cntx;
            minn+=max(cntz,cntx);
        }
        cout<<maxx<<' '<<minn<<endl;
    }
    return 0;
}
