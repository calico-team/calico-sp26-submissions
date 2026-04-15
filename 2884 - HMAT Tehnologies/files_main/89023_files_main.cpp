#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string A, B;
        cin >> A >> B;

        string out = A;
        size_t j = 0;

        for (size_t i = 0; i < A.size(); i++)
        {
            if (j < B.size() && A[i] == B[j])
            {
                j++;
            }
            else
            {
                out[i] = '#';
            }
        }

        cout << out << '\n';
    }

    return 0;
}
