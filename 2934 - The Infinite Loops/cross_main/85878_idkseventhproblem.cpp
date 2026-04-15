#include <algorithm>
#include <cstddef>
#include <cstdint>
//#include <filesystem>
#include <future>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <fstream>
#include <cassert>
#include <numeric>
#include <unordered_set>    
#include <map>
#include <unordered_map>
using namespace std;
//the ultimate testing testy .cpp where you can test to your test's desire
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int X, Y;
        cin >> Y >> X;
        int c = 0;
        for(int y = 0; y < Y; y++){
            int outputthis = c;
            if(c == 0){
                c = 2;
            } else if(c == 1){
                c = 3;
            } else if(c == 2){
                c = 4;
            } else if(c == 3){
                c = 0;
            } else if(c == 4){
                c = 1;
            }
            for(int x = 0; x < X; x++){
                outputthis++;
                if(outputthis == 5){
                    outputthis = 0;
                }

                cout << outputthis << " ";

            }
            cout << endl;
        }

    }

};
