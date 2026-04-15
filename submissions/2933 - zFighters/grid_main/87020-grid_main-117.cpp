#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const long long kInfinity=1e18;

vector<int> findOptimalPermutation(int n , const vector<int>& originalArray){
  
  vector<vector<long long>> dp(n, std::vector<long long>(n, kInfinity));
  
      vector<vector<int>> parentIndex(n, vector<int>(n, -1));
      
      for(int j=0;j<n ; ++j){
        dp[0][j]=0;
      }
      
        for (int i = 1; i < n; ++i) {
        for (int currIndex = 0; currIndex < n; ++currIndex) {
            
            for(int prevIndex=0 ; prevIndex<n; ++prevIndex){
            
            long long transitionCost = abs(originalArray[i] - originalArray[currIndex]) 
                                        + abs(originalArray[currIndex] - originalArray[prevIndex]);
                                        
                                        long long totalCost = dp[i - 1][prevIndex] + transitionCost;
                                        
                                        if (totalCost < dp[i][currIndex]) {
                    dp[i][currIndex] = totalCost;
                    parentIndex[i][currIndex]=prevIndex;
                }
            }
        }
}

 long long minimumCost = kInfinity;
    int bestLastIndex = 0;

    for (int j = 0; j < n; ++j) {
        if (dp[n - 1][j] < minimumCost) {
            minimumCost=dp[n-1][j];
            bestLastIndex=j;
        }
    }
    
    vector<int> selectedIndices(n);
    selectedIndices[n - 1] = bestLastIndex;

    for (int i = n - 1; i > 0; --i) {
        selectedIndices[i - 1] = parentIndex[i][selectedIndices[i]];
    }
    
    vector<int> resultArray(n);
    for (int i = 0; i < n; ++i) {
        resultArray[i] = originalArray[selectedIndices[i]];
    }
    return resultArray;
    
        }
        int main() {
          
          int testCases;
          cin>>testCases;
          
          while(testCases--){
            int n;
            cin>>n;
            
            vector<int> arr(n);
             for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        vector<int> result = findOptimalPermutation(n, arr);
        
        for (int i = 0; i < n; ++i) {
            std::cout << result[i] << " ";
        }
          }
          return 0;
      
          }

    