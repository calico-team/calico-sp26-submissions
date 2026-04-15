#include <bits/stdc++.h>
using namespace std;

long long getMedian(long long a, long long b, long long c)
{
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    return b;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<long long> the_two_tower_heights(N);

         the_two_tower_heights[0] = A[0];

        for (int i = 1; i < N - 1; i++)
        {
            the_two_tower_heights[i] = getMedian(
                the_two_tower_heights[i - 1],  
                A[i],                          
                A[i + 1]                       
            );
        }

        if (N > 1)
            the_two_tower_heights[N - 1] = A[N - 1];

        for (int i = 0; i < N; i++)
            cout << the_two_tower_heights[i] << " ";

        cout << "\n";
    }
}