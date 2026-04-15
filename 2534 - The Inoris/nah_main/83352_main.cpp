#include <iostream>
#include <vector>

using namespace std;
string solve(int N, int P, int R, int K, vector<int> E) {
	

    int k=0;

    if(P<E[0])
    {
        return "nah i'd lose";
    }


    for(int i=0;i<N;i++)
    {
        P-=E[i];
        k++;

        if(i!=N-1&&P<E[i+1])
        {
            if(k>=K)
            {
                P=R;
                k=0;
                continue;
            }
            else if(k<K)
            {
                return "nah i'd lose";
            }
        }

        
    }
    return "nah i'd win";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, P, R, K;
		cin >> N >> P >> R >> K;
		vector<int> E(N);
		for (int j = 0; j < N; j++) {
			cin >> E[j];
		}
        cout << solve(N, P, R, K, E) << '\n';
    }
}
