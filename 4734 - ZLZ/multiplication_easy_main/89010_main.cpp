#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Constraint {
    int Ri, Ci;
    long long Vi;
    int Wi;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, D;
    cin >> N >> M >> D;

    Constraint* cons = new Constraint[M];
    for (int i = 0; i < M; i++) {
        cin >> cons[i].Ri >> cons[i].Ci >> cons[i].Vi >> cons[i].Wi;
    }

    long long* a = new long long[N+1];
    for (int i = 1; i <= N; i++) a[i] = 1;

    // ��ʼ������ƽ��������
    for (int i = 0; i < M; i++) {
        int Ri = cons[i].Ri, Ci = cons[i].Ci;
        if (a[Ri] == 1 && a[Ci] == 1) {
            long long val = (long long)(sqrt((double)cons[i].Vi) + 0.5);
            if (val == 0) val = 1;
            a[Ri] = val;
            a[Ci] = max(1LL, cons[i].Vi / val);
        }
    }

    // ���� penalty
    double* penalties = new double[M];
    int* idxs = new int[M];
    for (int i = 0; i < M; i++) {
        long long pred = a[cons[i].Ri] * a[cons[i].Ci];
        double err = fabs((double)pred - cons[i].Vi) / cons[i].Vi;
        penalties[i] = cons[i].Wi * err;
        idxs[i] = i+1;
    }

    // ���� penalty ���� D ��Լ��
    sort(idxs, idxs+M, [&](int x, int y){
        return penalties[x-1] > penalties[y-1];
    });

    // ������
    for (int i = 1; i <= N; i++) {
        cout << a[i] << (i==N?'\n':' ');
    }
    cout << D;
    for (int i = 0; i < D; i++) cout << " " << idxs[i];
    cout << "\n";

    delete[] cons;
    delete[] a;
    delete[] penalties;
    delete[] idxs;
    return 0;
}
