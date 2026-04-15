#include <bits/stdc++.h>
using namespace std;

/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    // YOUR CODE HERE
    
    vector<int> x{0, 0, 1};
    vector<int> answer;
    
    answer = A;
    int val = 0;
    for(int i=1; i<N; i++)val += abs(A[i]-A[i-1]);
		
    do{
    	vector<int> cur = A;
    	for(int i=0; i<N; i++){
    		if(x[i] == 0)continue;	
			if(i == 0)cur[i] = cur[i+1];
			else cur[i] = cur[i-1];
		}
		
		int cnt = 0;
    	for(int i=1; i<N; i++)cnt += abs(cur[i]-cur[i-1]);
		for(int i=0; i<N; i++)cnt += abs(cur[i]-A[i]);	
    	
    	if(val == -1 || cnt < val){
    		val = cnt;
    		answer = cur;
		}
		
	}while(next_permutation(x.begin(), x.end()));
    
    sort(x.begin(), x.end());
    do{
    	vector<int> cur = A;
    	for(int i=0; i<N; i++){
    		if(x[i] == 0)continue;	
			if(i == 0)cur[i] = cur[i+1];
			else if(i == N-1)cur[i] = cur[i-1];
			else{
				if(x[i+1] == 1){
					cur[i] = cur[i+1];
				}else{
					cur[i] = cur[i-1];
				}
			}
		}
    	for(int i=0; i<N; i++){
    		if(x[i] == 0)continue;	
			if(i == 0)cur[i] = cur[i+1];
			else if(i == N-1)cur[i] = cur[i-1];
			else{
				if(x[i+1] == 1){
					cur[i] = cur[i+1];
				}else{
					cur[i] = cur[i-1];
				}
			}
		}
		
		int cnt = 0;
    	for(int i=1; i<N; i++)cnt += abs(cur[i]-cur[i-1]);
		for(int i=0; i<N; i++)cnt += abs(cur[i]-A[i]);	
    	
    	if(val == -1 || cnt < val){
    		val = cnt;
    		answer = cur;
		}
		
	}while(next_permutation(x.begin(), x.end()));
    
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
