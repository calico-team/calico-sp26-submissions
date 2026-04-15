#include <iostream>
using namespace std;

string gojo_fight() {
    int N, K, P, R;

    cin >> N >> P >> R >> K;

    int E[10000];

    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }

    int power = P;
    int count = 0;

    for (int i = 0; i < N; i++) {
        power -= E[i];

        if (power < 0) {
            return "nah i’d lose";
        }

        count++;

        if (count == K) {
            power += R;
            count = 0;
        }
    }

    return "nah i’d win";
}

void start_game() {
    int T;
    cin >> T;

    while (T--) {
        cout << gojo_fight() << "\n";
    }
}

int main() {
    start_game();
    return 0;
}