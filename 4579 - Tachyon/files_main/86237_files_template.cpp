#include <bits/stdc++.h>
#include <queue>
#define endl '\n'
using namespace std;

string solve(string A, string B) {
    /*

    A: the initial string
    B: the target stringq
    */
	


	queue<char> Bqueue;	
	for(char b: B){
		Bqueue.push(b);
	}
	for(int i(0);i<A.size();i++){
		if (Bqueue.empty()){
			A[i]='#';
		}
		else if(A[i]==Bqueue.front()){
			Bqueue.pop();
		}else{
			A[i]='#';
		}
	}
	return A;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}
