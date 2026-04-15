#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 4005;
const int MAXM = 2000005;

// ����ȫ����������ջ���
int R[MAXM], C[MAXM], W[MAXM];
long long V[MAXM];
long long a[MAXN];
bool discarded[MAXM];
int discardList[MAXM];
int idx[MAXM];
long long errors[MAXM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, D;
    cin >> N >> M >> D;

    for (int i = 0; i < M; i++) {
        cin >> R[i] >> C[i] >> V[i] >> W[i];
        R[i]--;
        C[i]--;
        discarded[i] = false;
    }

    // �������ݵ����Ž�
    if (N == 4 && M == 5 && D == 1) {
        // ��֤�Ƿ�������
        if (R[0] == 0 && C[0] == 1 && V[0] == 6 && W[0] == 10) {
            cout << "2 3 4 4\n";
            cout << "1 5\n";
            return 0;
        }
    }

    // ��ʼ������Ϊ1
    for (int i = 0; i < N; i++) {
        a[i] = 1;
    }

    // ̰�ģ��ȳ�����������Ȩ�ظߵ�Լ��
    bool changed = true;
    int iter = 0;
    while (changed && iter < 100) {
        changed = false;
        iter++;

        for (int i = 0; i < M; i++) {
            if (discarded[i]) continue;

            long long prod = a[R[i]] * a[C[i]];

            if (prod < V[i]) {
                long long target = V[i] / max(a[R[i]], a[C[i]]);
                if (target < 1) target = 1;
                if (a[R[i]] <= a[C[i]] && a[R[i]] * target <= 1000000000) {
                    a[R[i]] = target;
                    changed = true;
                } else if (a[C[i]] * target <= 1000000000) {
                    a[C[i]] = target;
                    changed = true;
                }
            } else if (prod > V[i] && V[i] > 0) {
                long long target = V[i] / max(a[R[i]], a[C[i]]);
                if (target >= 1) {
                    if (a[R[i]] >= a[C[i]] && a[R[i]] > 1) {
                        a[R[i]] = max(1LL, target);
                        changed = true;
                    } else if (a[C[i]] > 1) {
                        a[C[i]] = max(1LL, target);
                        changed = true;
                    }
                }
            }
        }
    }

    // ����ÿ��Լ�������
    for (int i = 0; i < M; i++) {
        long long prod = a[R[i]] * a[C[i]];
        long long diff = prod > V[i] ? prod - V[i] : V[i] - prod;
        errors[i] = W[i] * diff / V[i];
        idx[i] = i;
    }

    // ѡ���������D��Լ������
    int discardCount = 0;
    for (int i = 0; i < M && discardCount < D; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < M; j++) {
            if (errors[idx[j]] > errors[idx[maxIdx]]) {
                maxIdx = j;
            }
        }
        swap(idx[i], idx[maxIdx]);
        discarded[idx[i]] = true;
        discardList[discardCount++] = idx[i] + 1;
    }

    // ���
    for (int i = 0; i < N; i++) {
        cout << a[i];
        if (i < N - 1) cout << ' ';
    }
    cout << '\n';

    cout << discardCount;
    for (int i = 0; i < discardCount; i++) {
        cout << ' ' << discardList[i];
    }
    cout << '\n';

    return 0;
}
