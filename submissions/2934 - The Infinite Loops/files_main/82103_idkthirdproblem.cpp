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
using namespace std;
//the ultimate testing testy .cpp where you can test to your test's desire
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int indx = 0;
        string a, b;
        cin >> a >> b;
        string f = "";
        for(int j = 0; j < a.size(); j++){
            if(a[j] == b[indx]){
                f += b[indx];
                indx++;
            } else {
                f += '#';
            }
        }
        cout << f << endl;

    }

};
 