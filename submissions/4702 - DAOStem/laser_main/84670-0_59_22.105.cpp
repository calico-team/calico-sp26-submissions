#include <bits/stdc++.h>
using namespace std;

/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */
 
int hitindex = 0; 
 
bool check(pair<int, int> position, vector<pair<int,int>> coord){
    
    bool match = false;
    
    for(int i=0; i<coord.size(); i++){
        if(coord[i].first == position.first && coord[i].second == position.second){
            match = true;
            hitindex = i;
        }
    }

    return match;
} 

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	
	vector<pair<int, int>> coordinates;
	bool hitasteroid = false;
	
	//coordinates vector for matching
	for(int i=0; i<X.size(); i++){
	    coordinates.push_back(pair(X[i], Y[i]));
	}
	
	//start position
	pair<int, int> currentpos;
	currentpos.first = X[0];
	currentpos.second = Y[0];
	
	//if an asteroid has not yet been hit
	while(hitasteroid == false){
	    
	    //possible new positions without actual setting new positions
	    long long int newxpos = currentpos.first + Q;
	    long long int newypos = currentpos.second + P;
	    
	    //x movement
	    if(newxpos > N-1){
	        currentpos.first = abs(N - (currentpos.first + Q));
	    }
	    else{
	        currentpos.first += Q;
	    }
	    
	    //y movement
	    if(newypos > M-1){
	        currentpos.second = abs(M - (currentpos.second + P));
	    }
	    else{
	        currentpos.second += P;
	    }
	    
	    if(check(currentpos, coordinates) == true){
	        hitasteroid == true;
	        return hitindex;
	    }
	    
	    
	}
	
	return hitindex;
}


int main() {
	int T; cin >> T;
	while (T--) {
		int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<int> X(K), Y(K);
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}