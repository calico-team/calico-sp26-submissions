#include <iostream>
#include <vector>

using namespace std;

int main() {
int T;
cin >> T;
vector<int> L_memory(T);
vevtor<int> W_memory(T); 
vector<int> E_memory(T);
vector<int> R_memory(T);
for (int i = 0; i < T; i++) {
cin >> L_memory[i] >> W_memory[i] >> E_memory[i] >> R_memory[i];
}
vector<int> answer_memory(T);
for (int i = 0; i < T; i++) {
int L = L_memory[i];
int W = W_memory[i];
int E = E_memory[i];
int R = R_memory[i];
int perimeter = L + W + L + W;
int current_electricity = 0;
int laps = 0;
while (current_electricity < E) {
for (int step = 0; step < perimeter; step++) {
current_electricity = current_electricity + R;
}
laps = laps + 1;
}
answer_memory[i] = laps;
}
for (int i = 0; i < T; i++) {
cout << answer_memory[i] << endl;
}
return 0;
}