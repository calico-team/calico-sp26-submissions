#include <iostream>
#include <string>
using namespace std;

void solution(){
    string long_string, short_string;
    cin>>long_string;
    cin>>short_string;

    int a= 0;
    int b = 0;

    for (int i  = 0; i< long_string.length(); i++){
        if (b < short_string.length()){
            if (long_string[i] == short_string[b]){
                b++;
            }
            else{
                long_string[i] = '#';
            }
        }
        else{
            long_string[i] = '#';
        }
    }
    cout<<long_string<<endl;
}
int main(){
    int test_case;
    cin>>test_case;
    while (test_case >0){
        solution();
        test_case--;
    }
}