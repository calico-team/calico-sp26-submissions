#include<iostream>
using namespace std;
int main()
{
    int T;
    int Total_Laps;
    int EIOL;
    int L, W , E , R;
    cin >> T;
    for (int i = 0; i < T; i++) 
    {
        cin >> L >> W >> E >> R;
        int permimeter = 2 * (L + W);
        EIOL = permimeter * R;
        Total_Laps= E/EIOL;
        cout << Total_Laps << endl;
    }
    return 0;
}