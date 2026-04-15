#include <iostream>

using namespace std;

void domain_expansion(){


    int n,p,r,k;
    cin>>n>>p>>r>>k;

    int curses(10005);
    
    for (int i = 0; i < n; i++){
        cin >> curses[i];
    }

    bool win = true;
    for (int i = 0; i < n; i++){
        p = p -curses[i];
        if (p < 0){
            win = false;
            break;

        }
        int curses_defeated = i +1;
        if (curses_defeated%k == 0){
            p = p +r;
        }
    }
    if (win == true){
        cout<< "nah i'd win"<<endl;
    }
    else{
        cout<< "nah i'd lose"<<endl;
    }



}
int main(){
    int test_case;
    cin>>test_case;
    while (test_case>0){
        domain_expansion();
        test_case--;
    }
    return 0;
}