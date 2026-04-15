#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (auto& x : A) cin >> x;

        if (n == 1) cout << A[0];
        else if (n == 2) cout << A[0] << " " << A[1];
        else if (n == 3) 
        {
            vector<int> temp = A;
            sort(temp.begin(), temp.end());
            int b2 = temp[1]; 
            
            cout << A[0] << " " << b2 << " " << A[2];
        }
        
        cout << "\n";
    }
}