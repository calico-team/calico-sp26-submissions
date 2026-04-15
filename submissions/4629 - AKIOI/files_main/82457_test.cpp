#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    int T;
    cin >> T;
    string str1, str2;
    while (T--)
    {
        int ptr = 0, i = 0;
        cin >> str1 >> str2;
        while (ptr < str2.size())
        {
            if (str1[i] == str2[ptr])
                ptr++;
            else
                str1[i] = '#';

            i++;
        }
        for (; i < str1.size(); i++)
            str1[i] = '#';

        cout << str1 << endl;
    }

    return 0;
}
/*
5
ccaalliiccoo
calico
big_bens_bday
bbb
job
jb
include_over_californication
ilovecalico
six_seven_rizzler_sigma_banned_discord_skibidi_toilet
severance
*/