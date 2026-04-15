#include <iostream>
using namespace std;
int t;
int main()
{
    cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        int j = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[j])
                s1[i] = '#';
            else
                j++;
        }
        cout << s1;
    }
    return 0;
}