#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sol[n];
    sol[0] = arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        // pick the number between sol[i-1] and arr[i] closest to arr[i+1]
        int left = sol[i - 1];
        int right = arr[i];
        if (left > right)
            swap(left, right);
        if (left <= arr[i + 1] && arr[i + 1] <= right)
            sol[i] = arr[i + 1];
        else if (arr[i + 1] < left)
            sol[i] = left;
        else
            sol[i] = right;
    }
    int left = sol[n - 2];
    int right = arr[n - 1];
    if (left > right)
        swap(left, right);
    if (left <= arr[n - 1] && arr[n - 1] <= right)
        sol[n - 1] = arr[n - 1];
    else if (arr[n - 1] < left)
        sol[n - 1] = left;
    else
        sol[n - 1] = right;

    for (int i = 0; i < n; i++)
    {
        cout << sol[i] << ' ';
    }
    cout << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
