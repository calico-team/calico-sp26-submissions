#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
    int T;
    cin >> T;
    vector<pair<string, string>> cases(T);
    for(int i = 0; i < T; i++){
        cin >> cases[i].first;
        cin >> cases[i].second;
    }

    for(int i = 0; i < T; i ++){
        int indexFirst = 0;
        int indexSecond = 0;
        while(indexFirst < (int)cases[i].first.size() && indexSecond < (int)cases[i].second.size()){
            if(indexSecond < (int)cases[i].second.size() &&
               cases[i].first[indexFirst] == cases[i].second[indexSecond]){
                indexFirst++;
                indexSecond++;
            } else {
                cases[i].first[indexFirst] = '#';
                indexFirst++;
            }
            }
        while(indexFirst < (int)cases[i].first.size()){
            cases[i].first[indexFirst] = '#';
            indexFirst++;
        }
            cout << cases[i].first << endl;
        }
        return EXIT_SUCCESS;
}