#include <bits/stdc++.h>
using namespace std;

string censor_this_please(string A, string B)
{
    string res;
    int j = 0;
    for (char c : A)
	{
        if (j < B.size() && c == B[j])
		{
            res += c;
            j++;
        } 
		else
            res += '#';
    }
    return res;
}

void read_your_input()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
	{
        string A, B;
        getline(cin, A);
        getline(cin, B);
        cout << censor_this_please(A, B) << endl;
    }
}

int main()
{
    read_your_input();
    return 0;
}
