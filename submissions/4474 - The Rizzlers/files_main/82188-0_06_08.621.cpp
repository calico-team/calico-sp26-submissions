#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

int main() {
    FASTIO;
    ll t, cur;
    cin >> t;
    string a, b, ans;
    while (t--)
    {
        cur = 0;
        ans = "";
        cin >> a >> b;
        for (int i = 0; i < b.length(); i++)
        {
            while (a[cur] != b[i])
            {
                ans += "#";
                cur++;
            }
            ans += b[i];
            cur++;
        }

        while (cur < a.length())
        {
            ans += "#";
            cur++;
        }

        cout << ans << "\n";
    }

    return 0;
}

