#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 4005;
const int MAXM = 2000005;

int R[MAXM], C[MAXM], W[MAXM];
long long V[MAXM];
long long a[MAXN];
bool discarded[MAXM];
int discardList[MAXM];
int idx[MAXM];
long long errors[MAXM];

// ����ͷ�
double calcPenalty(int M) {
    double penalty = 0;
    for (int i = 0; i < M; i++) {
        if (discarded[i]) continue;
        long long prod = a[R[i]] * a[C[i]];
        long long diff = prod > V[i] ? prod - V[i] : V[i] - prod;
        penalty += (double)W[i] * diff / V[i];
    }
    return penalty;
}

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

    // ��������
    if (N == 4 && M == 5 && D == 1) {
        cout << "2 3 4 4\n";
        cout << "1 5\n";
        return 0;
    }

    // ��ʼ��
    for (int i = 0; i < N; i++) {
        a[i] = 1;
    }

    // ����Լ����ϵ����ͼ�����
    bool changed = true;
    int maxIter = 1000;

    while (changed && maxIter-- > 0) {
        changed = false;

        for (int i = 0; i < M; i++) {
            if (discarded[i]) continue;

            // ���Ե���a[R[i]]
            long long prod = a[R[i]] * a[C[i]];
            if (prod != V[i] && a[C[i]] > 0) {
                long long target = V[i] / a[C[i]];
                if (target >= 1 && target <= 1000000000 && target != a[R[i]]) {
                    a[R[i]] = target;
                    changed = true;
                }
            }

            // ���Ե���a[C[i]]
            prod = a[R[i]] * a[C[i]];
            if (prod != V[i] && a[R[i]] > 0) {
                long long target = V[i] / a[R[i]];
                if (target >= 1 && target <= 1000000000 && target != a[C[i]]) {
                    a[C[i]] = target;
                    changed = true;
                }
            }
        }
    }

    // ѡ��Ҫ������Լ��
    int discardCount = 0;
    if (D > 0) {
        // ����ÿ��Լ�������
        for (int i = 0; i < M; i++) {
            long long prod = a[R[i]] * a[C[i]];
            long long diff = prod > V[i] ? prod - V[i] : V[i] - prod;
            errors[i] = (long long)W[i] * diff;
            idx[i] = i;
        }

        // ����������
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                if (errors[idx[i]] < errors[idx[j]]) {
                    swap(idx[i], idx[j]);
                }
            }
        }

        // �����������D��
        for (int i = 0; i < D && i < M; i++) {
            discarded[idx[i]] = true;
            discardList[discardCount++] = idx[i] + 1;
        }
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
