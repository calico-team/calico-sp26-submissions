#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
  
  int MAXIMAL = 0;
  int MINIMAL = 0;
  
    for(int i = 0; i < N; i++){
      
      int Block1 = 0, Block2 = 0;
      
      for(int j = 0; j < N; j++){
        
        if(S1[i][j] == '#'){
          
          Block1++;
          
        }
        
        if(S2[i][j] == '#'){
          
          Block2++;
          
        }
        
      }
      
      MAXIMAL += Block2 * Block1;
      MINIMAL += max(Block2, Block1);
      
    }
    
    string Answer = to_string(MAXIMAL) + " " + to_string(MINIMAL);
    
    return Answer;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}
