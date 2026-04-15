#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
        string a;
        string b;
        cin >> a >> b;
        int replaced_in_b = 0;
        int length_a = a.size();
        for(int j = 0;j < length_a;j++){
            if(a[j] == b[replaced_in_b]){
                replaced_in_b++;
            }
            else{
                a[j] = '#';
            }
        }
        cout << a << endl;
    }
    return 0;
}