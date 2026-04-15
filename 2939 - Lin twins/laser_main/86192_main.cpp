#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include<map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
typedef long long ll;
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
pair<int, int> timeStep(int &currentX, int &currentY, int deltaX, int deltaY, int width, int height){
	currentX += deltaX;
	currentY += deltaY;
	if(currentX>= width){
		currentX -=width ;
	}else if(currentX < 0){
		currentX +=width;
	}

	if(currentY>= height){
		currentY -=height ;
	}else if(currentY < 0){
		currentY +=height;
	}
	return make_pair(currentX, currentY);
}
int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	// YOUR CODE HERE
	//k=asteroid, n = x width, m = ywidth, p=y and q=x are slope
	int startingX = X[0], startingY = Y[0];
    unordered_map<int, int> allCoords;
    for(int i = 0; i < X.size(); i++){
        allCoords[X[i]] = Y[i];
    }
    // cout<<endl;
    pair<int, int> firstPair;
    // int count = 0;
	while(true){
        // count++;
		pair<int, int> newCoords = timeStep(startingX, startingY, Q, P, N, M);
        // cout<<newCoords.first<<' '<<newCoords.second<<endl;
        if( allCoords.find(newCoords.first) != allCoords.end() && allCoords[newCoords.first]==newCoords.second ){//if x's are the smae and y's are the same allCoords[newCoords.first] == newCoords.second
            // cout<<newCoords.first<<' '<<newCoords.second<<endl;
            // for (const auto& [key, value] : allCoords) {
            //     std::cout << key << ": " << value << std::endl;
            // }


            firstPair = newCoords;
            // cout<<firstPair.first<<' ' <<firstPair.second<<endl;
            break;
        }
		// cout<<newCoords.first<<' ' <<newCoords.second<<endl;
		// break;
	}

    for(int i = 0; i < X.size(); i++){
        if(firstPair.first == X[i] && firstPair.second == Y[i]){
            return i;
        }
    }
    return 0;
    // cout<<firstPair.first<<" "<<firstPair.second<<endl;
	
}


int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("temporary.in");//temporary
    ofstream fout("temporary.out"); 
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