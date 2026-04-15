
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
    while(t--){
        string a, b;
        cin >> a;
        cin >> b;
        int bindex=0;
        for(int i = 0; i<a.size(); i++){
            if(a[i]!=b[bindex]){
                a[i]='#';
            }else{
                bindex++;
                continue;
            }
        }
        cout << a << "\n";
    }
}
