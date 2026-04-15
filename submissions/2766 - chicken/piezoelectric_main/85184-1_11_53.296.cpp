
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;


int main() {
   int T;
    if (!(cin >> T)) return 0;
    string a;
    getline(cin,a);
    while (T--) {
        int L,W,R,E;
        cin>>L>>W>>E>>R;
        int perimeter=(L+W)*2;
        double LAP;
        LAP=E / (R * perimeter);
        int result = std::ceil(LAP);
        cout<<result<<endl;
    }
    return 0;
}
