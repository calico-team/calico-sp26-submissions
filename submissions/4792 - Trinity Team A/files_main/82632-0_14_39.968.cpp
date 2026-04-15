#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> results;
    while(n--){
        int counter = 0;
        string A, B;
        string C = "";
        cin >> A >> B;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[counter]){
                counter++;
                C += A[i];
            }
            else{
                C += "#";
            }
        }
        results.push_back(C);
    }
    for(string i : results){
        cout << i << endl;
    }
}