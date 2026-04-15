#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int i;
};

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        Node A[1000][1000]={0};
        int K, N, M, P, Q, X, Y, ix, iy;
        cin>>K>>N>>M>>P>>Q;
        cin>>X>>Y;
        Y=N-Y-1;
        A[Y][X].i=0;
        iy=Y;
        ix=X;
        for (int i=1; i<K; i++)
        {
            int x, y;
            cin>>x>>y;
            A[N-y-1][x].i=i;
        }

        // for (int i=0; i<N; i++)
        // {
        //     for (int j=0; j<M; j++)
        //     {
        //         cout<<A[i][j].i<<' ';
        //     }
        //     cout<<endl;
        // }
        // // cout<<endl;

        while (A[Y][X].i==0)
        {
            Y-=P;
            X+=Q;
            if (Y<=0) Y=N+Y%N-1;
            if (X>=M-1) X=X%M+1;
            if (A[Y][X].i!=0||Y==iy&&X==ix)
            {
                cout<<A[Y][X].i<<endl;;
                break;
            }
        }
        // cout<<endl;
    }

    return 0;
}






