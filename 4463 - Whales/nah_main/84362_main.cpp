#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        int N, P, R, K, k=0;
        bool c=true;
        cin>>N>>P>>R>>K;
        for (int i=0; i<N; i++)
        {
            int C;
            cin>>C;

            P-=C;

            if (k==K)
            {
                P+=R;
                k=0;
            }

            if (P<0&&c)
            {
                cout<<"nah i’d lose\n";
                c=false;
            }

            k++;

        }
        if (c) cout<<"nah i’d win\n";
    }

    return 0;
}