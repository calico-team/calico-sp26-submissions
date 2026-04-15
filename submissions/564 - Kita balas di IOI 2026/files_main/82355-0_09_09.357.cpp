#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin >> t;

        while (t --> 0) {
                string s, t;
                cin >> s >> t;

                int j = 0;
                for (int i = 0; i < (int)s.size(); i++) {
                        if (j == (int)t.size() || s[i] != t[j]) {
                                s[i] = '#';
                        } else {
                                j++;
                        }
                }

                cout << s << '\n';
        }
        
        return 0;
}